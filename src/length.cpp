#include "r_trie.h"

template <typename T>
int radix_len(SEXP radix){
  r_trie <T>* rt_ptr = (r_trie <T> *) R_ExternalPtrAddr(radix);

  if (rt_ptr == NULL){
    stop("invalid trie object; pointer is NULL");
  }

  return rt_ptr->radix_size;
}

//[[Rcpp::export]]
int radix_len_string(SEXP radix){
  return radix_len<std::string>(radix);
}

//[[Rcpp::export]]
int radix_len_integer(SEXP radix){
  return radix_len<int>(radix);
}

//[[Rcpp::export]]
int radix_len_numeric(SEXP radix){
  return radix_len<double>(radix);
}


//[[Rcpp::export]]
int radix_len_logical(SEXP radix){
  return radix_len<bool>(radix);
}
