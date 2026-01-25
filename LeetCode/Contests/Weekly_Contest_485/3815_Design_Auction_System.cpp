/*
Problem: 3815. Design Auction System

Design an auction system that manages bids from multiple users in real time.  
Each bid has a userId, an itemId, and a bidAmount.

Implement the AuctionSystem class:

- AuctionSystem(): Initializes the system.
- addBid(userId, itemId, bidAmount): Adds or updates a bid for the item.
- updateBid(userId, itemId, newAmount): Updates an existing bid (guaranteed to exist).
- removeBid(userId, itemId): Removes an existing bid (guaranteed to exist).
- getHighestBidder(itemId): Returns the userId with the highest bidAmount.  
  If multiple users have the same highest bid, return the highest userId.  
  Return -1 if no bids exist.

Approach:
- Maintain a map of user bids per item (`user[itemId][userId] = bidAmount`).
- Maintain a sorted set per item to track bidAmount and userId for efficient retrieval of the highest bidder.
- For add/update, update both the map and set.
- For remove, delete from both map and set, cleaning up if the item has no bids.
- For getHighestBidder, return the userId with the largest bidAmount (tie-breaker: largest userId).

Time Complexity:
- addBid, updateBid, removeBid: O(log n) per operation due to set insertion/removal
- getHighestBidder: O(1)

Space Complexity: O(n) for storing bids
*/

class AuctionSystem {
public:
    unordered_map<int, unordered_map<int, int>> user;
    unordered_map<int, set<pair<int, int>>> item;
    
    AuctionSystem() {
    }
    
    void addBid(int userId, int itemId, int bidAmount) {
        if(user[itemId].count(userId)){
            int old = user[itemId][userId];
            item[itemId].erase({old, userId});
        }
        item[itemId].insert({bidAmount, userId});
        user[itemId][userId] = bidAmount;
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        int old = user[itemId][userId];
        item[itemId].erase({old, userId});
        item[itemId].insert({newAmount, userId});
        user[itemId][userId] = newAmount;
    }
    
    void removeBid(int userId, int itemId) {
        int old = user[itemId][userId];
        item[itemId].erase({old, userId});
        user[itemId].erase(userId);
        if(user[itemId].empty()){
            user.erase(itemId);
            item.erase(itemId);
        }
    }
    
    int getHighestBidder(int itemId) {
        if(item.find(itemId) == item.end() || item[itemId].empty()){
            return -1;
        }
        auto res = prev(item[itemId].end());
        return res->second;
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */
