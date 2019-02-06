#include "serial.h"
#include "memory/kheap.h"
#include "stdio.h"
#include "stderr.h"

extern const volatile char heap_top;
extern const volatile char heap_bottom;

static heap_size_t available_size;

static struct heap_control_t * ROOT = 0;

int get_heap_size() {
   return (int)((uint32_t) & heap_top - (uint32_t) & heap_bottom);
} 

void handle_memory_error(registers_t *registers) {
   registers = 0;
}

void init_heap() {

   HEAP_ADDR start = (HEAP_ADDR) & heap_bottom;

   //create a header block , as of now, only a empty control block is there with no data, occupying only 
   // 24bits (3b) of data, struct * heap_control_t is not occupied any memory
   struct heap_control_t * node = (struct heap_control_t * ) start;

   //init control block
   node->magic = HEAP_FREE;
   node->is_head = HEAP_HEAD;
   node->size = get_heap_size() - sizeof(struct heap_control_t);
   node->heap_next = 0;
   node->heap_previous = 0;

   ROOT = node;

   //("SIZE : %d\n", node->size);

   set_custom_error_handler(handle_memory_error);

   available_size = get_heap_size() - sizeof(struct heap_control_t);
}

//an internal kernel function , this implements the functionlaity of kalloc()
void * allocate_heap_memory(unsigned int size) {
  //start from ROOT
   struct heap_control_t * block = ROOT;
   struct heap_control_t *next_block = 0;

   void * buffer = 0,  * next_buffer = 0;

   HEAP_ADDR heap_pointer ;

   //proceed in farword direction, some implementations can try allocation in backwrad direction also
   for(block = ROOT; block; block = block->heap_next) {
       heap_pointer = (HEAP_ADDR) block;

       if(block->is_head != HEAP_HEAD)  {
          call_stderr();
          return buffer; //returns a null pointer, any code that calls this function may hence check for NULLs before using memory
       }
       if(block->magic == HEAP_FREE && block->size >=  size) {
         //we found a block where we can allocate
         buffer = (HEAP_ADDR) (heap_pointer + sizeof(struct heap_control_t));
         block->magic = HEAP_ALLOCATED;

         if(block->size <= (size + sizeof(struct heap_control_t))) return buffer;

         //here, everything if fine for allocation, we can allocate
         next_buffer = (HEAP_ADDR ) (buffer + size);
         next_block = (struct heap_control_t *) next_buffer;


         //now create a double link structure

         //set metadata
         next_block->is_head = HEAP_HEAD;
         next_block->magic = HEAP_FREE;
         next_block->size = block->size - (size + sizeof(struct heap_control_t));

         //link it to previous block
         next_block->heap_previous = block;
         next_block->heap_next = 0;

         block->heap_next = next_block;
         block->size = size;

         available_size = available_size - (size + sizeof(struct heap_control_t));

         return buffer;
       }
   }

   return buffer;
}


struct heap_control_t * get_header(void *ptr) {
    return (struct heap_control_t *) (ptr - sizeof(struct heap_control_t)) ;
}

//sub-function of free()
void heap_merge(struct heap_control_t * head, struct heap_control_t * tail) {
    struct heap_control_t *bound;

    if(head->is_head == HEAP_HEAD && tail->is_head == HEAP_HEAD) {
      if(head->heap_next != (HEAP_ADDR)tail || tail->heap_previous != (HEAP_ADDR)head) return;
      if((HEAP_ADDR)head + sizeof(struct heap_control_t) + head->size != (HEAP_ADDR)tail) return;

      //unlink :
      if(tail->heap_next) {
        bound = (struct heap_control_t *)tail->heap_next;
        bound->heap_previous = head;
      }

      head->heap_next = tail->heap_next;
      head->size += (sizeof(struct heap_control_t) + tail->size);

    }
}

int get_free_kheap_size() {
  return (int) available_size;
}

void release_heap(void *pointer) {
   struct heap_control_t  * block = get_header(pointer);

   //checks
   if(block->is_head != HEAP_HEAD) {
     call_stderr();
     return;
   }

   if(block->magic == HEAP_ALLOCATED) {

      //set free
      block->magic = HEAP_FREE;
      block->is_head = HEAP_HEAD;

      available_size += (sizeof(struct heap_control_t) + block->size);

      if(block->heap_next) {
         heap_merge(block, (struct heap_control_t *)block->heap_next);
      }

      if(block->heap_previous) {
        heap_merge((struct heap_control_t *)block->heap_previous, block);
      }
   }
}