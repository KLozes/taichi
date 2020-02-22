#pragma once

#include <upcxx/backend.hpp>
#include <iostream>
#include <sstream>

// A structure to handle the UPC++ runtime

TLANG_NAMESPACE_BEGIN

class TaichiUPCxxContext {
public:
  int rank_me;
  int rank_n;
  int rank_me_local; // rank local to node
  int rank_n_local;

  TaichiUPCxxContext(){
    upcxx::init();
    rank_me = upcxx::rank_me();
    rank_n = upcxx::rank_n();
    rank_me_local = upcxx::local_team().rank_me();
    rank_n_local = upcxx::local_team().rank_n();

    std::ostringstream oss;
    oss << "Hello from "<<rank_me<<" of "<<rank_n<<'\n';
    std::cout << oss.str() << std::flush;
  }

  ~TaichiUPCxxContext(){
    upcxx::finalize();
  }

};


TLANG_NAMESPACE_END
