// Copyright 2010-2014 RethinkDB, all rights reserved.
#ifndef BTREE_NEW_LEAF_HPP_
#define BTREE_NEW_LEAF_HPP_

class buf_ptr_t;

struct orig_btree_t;

template <class btree_type>
struct new_leaf {
    static buf_ptr_t init();
};

#endif /* BTREE_NEW_LEAF_HPP_ */
