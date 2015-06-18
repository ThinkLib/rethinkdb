// Copyright 2010-2015 RethinkDB, all rights reserved.
#ifndef CLUSTERING_TABLE_CONTRACT_COORDINATOR_BRANCH_HISTORY_GC_HPP_
#define CLUSTERING_TABLE_CONTRACT_COORDINATOR_BRANCH_HISTORY_GC_HPP_

/* The branch history is stored in the Raft state and again on disk on each replica. Each
replica's B-tree metainfo refers to some branches, and the `current_branches` field in
the Raft state also refers to branches. When backfilling, we use the branch history to
find the relationship between the backfiller's B-tree metainfo state and the backfillee's
B-tree metainfo state. The coordinator uses the branch history to find the relationship
between the replicas' B-tree metainfo states and the branches in the contracts in the
Raft state.

Whenever `calculate_contracts()` is going to add a new entry to `current_branches`, it
calls `copy_branch_history_for_branch()` to add the branch history for the newly-added
branch. */

void copy_branch_history_for_branch(
        const branch_id_t &new_branch,
        const branch_history_t &source,
        const table_raft_state_t &old_state,
        branch_history_t *add_branches_out)

/* For performance reasons, we don't want the branch history to grow without bound. But
we want to make sure to preserve enough history to calculate the relationships between
the branches. So for each shard, the coordinator computes the common ancestor of the
branches in the contracts and the branches in the replicas' B-tree metainfos; it keeps
only those branches that are along the path between that common ancestor and the branches
in the contracts. The coordinator can compute that common ancestor using the replicas'
contract acks. Each individual replica also keeps those branches that are along the path
from the common ancestor to its current B-tree metainfo branches. The contract executor
on each replica determines the common ancestor by looking at the list of branches in the
Raft state. */

#endif /* CLUSTERING_TABLE_CONTRACT_COORDINATOR_BRANCH_HISTORY_GC_HPP_ */

