#ifndef SMARTCALC_SMART_CALC_H_
#define SMARTCALC_SMART_CALC_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data_structures.h"

#ifdef DEBUG
#define log_info(M, ...) \
  fprintf(stderr, "[INFO] (%s:%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#else
#define log_info(M, ...)
#endif

enum error_codes {
  OK,
  UNDEFINED_TOKEN,
  DATA_STRUCT_UNDERFLOW,
  DATA_STRUCT_OVERFLOW,
  TOO_LONG_STRING,
  EMPTY_EXPRESSION,
  MEMORY_ACCESS_ERROR,  // ! test_split_string_to_tokens.c
  UNBALANCED_BRACKETS,
  EMPTY_BRACKETS,
  INCORRECT_INPUT,
  EMPTY_QUEUE,
  STACK_UNDERFLOW,  // ! push.c
  STACK_OVERFLOW,   // ! push.c
  QUEUE_OVERFLOW    // ! push.c
};

#define ERRORS_MESSAGES_NUMBERS 14
#define ERRORS_MESSAGE_MAX_SIZE 22
#define ERRORS_MESSAGES                                                 \
  char errors_msg[ERRORS_MESSAGES_NUMBERS][ERRORS_MESSAGE_MAX_SIZE] = { \
      "OK",                                                             \
      "UNDEFINED_TOKEN",                                                \
      "DATA_STRUCT_UNDERFLOW",                                          \
      "DATA_STRUCT_OVERFLOW",                                           \
      "TOO_LONG_STRING",                                                \
      "EMPTY_EXPRESSION",                                               \
      "MEMORY_ACCESS_ERROR",                                            \
      "UNBALANCED_BRACKETS",                                            \
      "EMPTY_BRACKETS",                                                 \
      "INCORRECT_INPUT",                                                \
      "EMPTY_QUEUE",                                                    \
      "STACK_UNDERFLOW",                                                \
      "STACK_OVERFLOW",                                                 \
      "QUEUE_OVERFLOW"}

#define MATH_FUNCTIONS_NUMBER 9
#define MATH_FUNCTIONS_NAMES_LENGTH 5
#define MATH_FUNCTIONS_NAMES                                   \
  const char math_functions_names                              \
      [MATH_FUNCTIONS_NUMBER][MATH_FUNCTIONS_NAMES_LENGTH] = { \
          "cos",  "sin",  "tan", "acos", "asin",               \
          "atan", "sqrt", "ln",  "log"}  // sequence is the same that in
                                         // "typedef enum token_type {...}
                                         // token_t"

#define CALC_FUNCTIONS_NUMBER 17
#define CALC_FUNCTIONS_POINTERS                                   \
  double (*calc_functions[CALC_FUNCTIONS_NUMBER])() = {           \
      cos,      sin,       tan,      acos,     asin,    atan,     \
      sqrt,     log,       log10,    u_plus,   u_minus, add_calc, \
      sub_calc, mult_calc, div_calc, mod_calc, pow_calc}
// sequence is the same that in "typedef enum token_type {...} token_t", but
// without OPEN_BRACKET

// FUNCTIONS
// data structures processing
int push(int address, node_t** phead, node_t* pdata);
int pop(node_t** s_phead, node_t* pnode);
void fill_node(node_t* src, node_t* dest);
void remove_head_node(node_t** phead);
void remove_struct(node_t** phead);
int move_node_from_queue_to_stack(node_t** q_phead, node_t** s_phead);
int move_node_from_stack_to_queue(node_t** s_phead, node_t** q_phead);

// calculator
int split_string_to_tokens(const char* str, char** tokens);
int convert_infix_to_RPN(const char* str, node_t** q_phead);
int evaluate_expression(node_t* q_root, double variable, double* result);
int numerical_calculation(node_t** s_phead, token_t function_id);

#endif  // SMARTCALC_SMART_CALC_H_