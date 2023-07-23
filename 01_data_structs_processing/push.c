/**
 * @author T. Enikeev
 * enikeeev.tg@gmail.com
 */

#include "../smart_calc.h"

/// @brief the data adding to stack new node
/// @param address STACK or QUEUE structure
/// @param phead head of structure
/// @param pdata
/// @return error code
int push(int address, node_t** phead, node_t* pdata) {
  int error = DATA_STRUCT_OVERFLOW;
  node_t* new_node_ptr = (node_t*)calloc(1, sizeof(node_t));
  if (new_node_ptr != NULL) {
    error = OK;
    if (address == STACK) new_node_ptr->pnext = *phead;
    if (address == QUEUE && *phead != NULL) (*phead)->pnext = new_node_ptr;
    fill_node(pdata, new_node_ptr);
    *phead = new_node_ptr;
  }
  return error;
}
