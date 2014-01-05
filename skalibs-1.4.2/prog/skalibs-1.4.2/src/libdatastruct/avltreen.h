/* ISC license. */

#ifndef AVLTREEN_H
#define AVLTREEN_H

#include "functypes.h"
#include "freelist.h"
#include "genset.h"
#include "avlnode.h"


 /* avltreen: just the structure. Storage and bits are outside. */

typedef struct avltreen_s avltreen, *avltreen_ref ;
struct avltreen_s
{
  genset x ;
  unsigned int root ;
  uintcmpfunc_t_ref cmp ;
  void *external ;
} ;

#define AVLTREEN_ZERO { GENSET_ZERO, (unsigned int)-1, 0, 0 }
#define avltreen_totalsize(t) ((t)->x.max)
#define avltreen_len(t) genset_n(&(t)->x)
#define avltreen_nodes(t) ((avlnode_ref)(t)->x.storage)
#define avltreen_data(t, i) (avltreen_nodes(t)[i].data)
#define avltreen_root(t) ((t)->root)
#define avltreen_setroot(t, r) ((t)->root = (r))
extern void avltreen_init (avltreen_ref, avlnode_ref, char *, unsigned int, uintcmpfunc_t_ref, void *) ;

#define avltreen_searchnode(t, k) avlnode_searchnode(avltreen_nodes(t), avltreen_totalsize(t), avltreen_root(t), (k), (t)->cmp, (t)->external)
#define avltreen_search(t, k, data) avlnode_search(avltreen_nodes(t), avltreen_totalsize(t), avltreen_root(t), (k), (data), (t)->cmp, (t)->external)

#define avltreen_height(t) avlnode_height(avltreen_nodes(t), avltreen_totalsize(t), avltreen_root(t))

#define avltreen_extremenode(t, h) avlnode_extremenode(avltreen_nodes(t), avltreen_totalsize(t), avltreen_root(t), h)
#define avltreen_minnode(t) avltreen_extremenode((t), 0)
#define avltreen_maxnode(t) avltreen_extremenode((t), 1)

#define avltreen_extreme(t, h, data) avlnode_extreme(avltreen_nodes(t), avltreen_totalsize(t), avltreen_root(t), (h), data)
#define avltreen_min(t, data) avltreen_extreme((t), 0, data)
#define avltreen_max(t, data) avltreen_extreme((t), 1, data)

extern unsigned int avltreen_newnode (avltreen_ref, unsigned int) ;
#define avltreen_insertnode(t, i) avltreen_setroot(t, avlnode_insertnode(avltreen_nodes(t), avltreen_totalsize(t), avltreen_root(t), i, (t)->cmp, (t)->external))
extern int avltreen_insert (avltreen_ref, unsigned int) ;

#define avltreen_deletenode(t, i) avltreen_delete(t, avltreen_data(t, i))
extern int avltreen_delete (avltreen_ref, unsigned int) ;

#define avltreen_iter(t, f, p) avlnode_iter(avltreen_nodes(t), avltreen_totalsize(t), avltreen_root(t), f, p)


 /* avltreeb: everything in one place. Stack or BSS, or heap if you insist */

#define AVLTREEB_TYPE(size) struct { avlnode storage[size] ; char freelist[size * freelist_size(size)] ; avltreen info ; }
#define avltreeb_init(t, size, f, p) avltreen_init(&(t)->info, (t)->storage, (t)->freelist, size, f, p)
#define avltreeb_totalsize(t) avltreen_totalsize(&(t)->info)
#define avltreeb_len(t) avltreen_len(&(t)->info)
#define avltreeb_nodes(t) ((avlnode_ref)(t)->storage)
#define avltreeb_data(t, i) (avltreeb_nodes(t)[i].data)
#define avltreeb_root(t) ((t)->info.root)
#define avltreeb_setroot(t, r) ((t)->info.root = (r))

#define avltreeb_searchnode(t, k) avlnode_searchnode(avltreeb_nodes(t), avltreeb_totalsize(t), avltreeb_root(t), (k), (t)->info.cmp, (t)->info.external)
#define avltreeb_search(t, k, data) avlnode_search(avltreeb_nodes(t), avltreeb_totalsize(t), avltreeb_root(t), (k), (data), (t)->info.cmp, (t)->info.external)
#define avltreeb_height(t) avlnode_height(avltreeb_nodes(t), avltreeb_totalsize(t), avltreeb_root(t))

#define avltreeb_extremenode(t, h) avlnode_extremenode(avltreeb_nodes(t), avltreeb_totalsize(t), avltreeb_root(t), h)
#define avltreeb_minnode(t) avltreeb_extremenode((t), 0)
#define avltreeb_maxnode(t) avltreeb_extremenode((t), 1)

#define avltreeb_extreme(t, h, data) avlnode_extremenode(avltreeb_nodes(t), avltreeb_totalsize(t), avltreeb_root(t), (h), data)
#define avltreeb_min(t, data) avltreeb_extreme((t), 0, data)
#define avltreeb_max(t, data) avltreeb_extreme((t), 1, data)

#define avltreeb_newnode(t, k) avltreen_newnode(&(t)->info, k)
#define avltreeb_insertnode(t, i) avltreeb_setroot(t, avlnode_insertnode(avltreeb_nodes(t), avltreeb_totalsize(t), avltreeb_root(t), i, (t)->info.cmp, (t)->info.external))
#define avltreeb_insert(t, k) avltreen_insert(&(t)->info, k)

#define avltreeb_deletenode(t, i) avltreeb_delete(t, avltreeb_data(t, i))
#define avltreeb_delete(t, k) avltreen_delete(&(t)->info, k)

#define avltreeb_iter(t, f, p) avlnode_iter(avltreeb_nodes(t), avltreeb_totalsize(t), avltreeb_root(t), f, p)

#endif
