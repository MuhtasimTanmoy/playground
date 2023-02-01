# System Design

## To Do
- System Design Book finish ✅
- Practise on Bluestash 

## Approach
- ASK Questions
- Walk me through a scenario of you using this system as a user
- What is the first feedback you have from the design so far? I am looking for negative feedback so I dont make it
    - Just this simple feedback loop can improve can improve a system so much in short time?
    - Let's add metrics for each of the system to find potential bottleneck
    - I need a second eye perspective
    - Your contact point is your customer
- Highlight human availability, and their skill
- Design a system that barely works
- Identify it's constraints then optimize
- Should go for optimized solution then go into details
- Discuss principle, keeping, fetching similar things together, improving cache locality

## Steps of System Design
- Requirement clarification
- Back of the envelope Estimation
- System interface definition
- Define data model
- High level design
- Detailed Design
- Identifying and resolving bottlenecks

## Amazon
- Basic Architecture
- Database table
- API
- Class diagram

## Flipcart
    - Functional
    - Non-Functional

- Identify the point of interest
    - Recommendation Service
    - Archival Service
    - Notification Service
    - Spark Streaming Service
    - Hadoop Cluster
    - Elastic Search

- Database design
    - Non-functional requrements 
    - Parameters
    - Strucutred
    - Query pattern
    - Redis 
        - Cache
    - Image/ Video 
        - Blob Storage
    - CDN 
        - Location aware blob
    - Search
        - Elastic Search
        - Solr
        - Apache luceen, fuzzy search, not primary

- Metrics type data, time series database, append only 
- Analytics - and query - offline reporting
- Transactional
    - Consistent
- Unstructured data with ability to search on attribute no SQL 
    - MongoDB
    - CouchDB
    - Document db
- Query limited data large 
    - Columner database
- Persist orders on mySQL then after delivered shift to cassandra, query part mongo db
- Video streaming

## Notification Service
    - Functional
        - Send Notification
        - Topic wise notification
        - Token wise notification
        - SAAS product
            - Rate Limiting
                - Transactional Notification
                - Promotional Notification
        - Prioritization
        - Pay per use
        - User preference to unsubscribe
        - Pluggable handler
        - Bulk notification
    - Non-Functional
        - Scalable
        - Reliable
        - Available
    - reverse proxy in frontend service
    - meta data service is distributed cache
    - no sql db type
    - database, in memory, message queue, stream processing
    -  subscriber list can be long, document db stores long messages

- Twitter
    - Functional
        - Tweet
        - Retweet
        - Follow
        - Search
    - Non-Functional
        - Read-Heavy
        - Low latency

## Rate Limitter
- Accurately limit excessive requests
- Low latency. The rate limiter should not slow down HTTP response time
- Use as little memory as possible
- Distributed rate limiting. The rate limiter can be shared across multiple servers or processes
- Exception handling. Show clear exceptions to users when their requests are throttled
- High fault tolerance
- If there are any problems with the rate limiter (for example, a cache server goes offline), it does not affect the entire system
- Start with something simple
- Autoscale takes time
- Cant know which process/ api takes how much time
- Rate limitter Algorithm
- The object oriented design
- The distributed portion
- Algorithm
    • Token bucket
    • Leaking bucket
    • Fixed window counter
    • Sliding window log
    • Sliding window counter

The client sends a request to rate limiting middleware
• Rate limiting middleware fetches the counter from the corresponding bucket in Redis and checks if the limit is reached or not.

Rate limiter in a distributed environment
Building a rate limiter that works in a single server environment is not difficult. However, scaling the system to support multiple servers and concurrent threads is a different story. There are two challenges:
• Race condition
• Synchronization Issue
    - Sticky Sessions

```c++
Class TokenBucket {
    public:
    TokenBucket() {

    }
    private:
        long maxBucketSize;
        long currentBucketSize;
        double refillRate;
        long lastRefillTime;
}
```

# Distributed Cache
- Amazing

# Google Maps
- Google Maps
    - Identify road, path, distance, routes, ETA
    - Pluggable model to add new feature, like free path, jam, construction without making any change to the architecture

# Google Doc
- Differential Syncronization

# Twitter System Design
- User service
- Graph Service
    - Follow Process
        - Get all the person user is following
        - Get all followers who is following
    - Cassandra
    - Hbase
        - Zookeeper
        - Hadoop
- Search Service
- Post a tweet service
    - Tiny URL
    - Media service
    - Famous user
    - Inactive users
- Analytics
    - ML to passive users interest

# Facebook
- User Service
- Add post
- Access pattern
- Different resoulution
- Post ingestion service 
- ML classification
- Cassandra for archival
- Dont create hotspot using date
- Like service
- Graph weight job
- Trends wotd top k

# Count Min Sketch
- Probabilistic Data Structure

# Parking Lot Design
- Requirement Collection
- Object Oriented Class Design

# Distributed Message Queue
- Syncronous Communication to Asyncronous
    - Failed request retry
    - Overwhelm consumer, backpressure
    - Slow consumer
- Topic 
    - Published message goes to each and every subscriber
    - Queue one consumer
- Client
- VIP
- Load Balancer
    - Single point of failure
        - Primary and secondary node, failover case
    - Scalibility
        - VIP partioning
        - Multiple A DNS
- Frontend web service
    - Stateless
    - Request validation
        - All required params present
        - Data falls within acceptable range
        - Message size dont exceed certain threshold 
        - Why needed? If all clients are strictly controlled by us then we can enforce it with communication
        - But if this api is consumed by other clients or third party service this one is needed
    - Authentication/ Authorization
        - is a registered account
        - is allowed tosend request
    - TLS
        - TLS on the load balancer is expensive
        - Handled by a separate TLS HTTP Proxy that
    - Server side Encryption
        - Messages are stored in encrypted form and only decrypted when sending back to consumer
    - Caching
    - Rate limiting
        - Leaky bucket
    - Request dispatching
        - Metadata service
        - Backend service
        - Call Isolation
            - BulkHead
            - Circuit breaker
    - Request deduplication
        - When successful send message failed to send to client
        - Lesser issue for at least once delivery semantics
        - Bigger issue for at most once, exactly once delivery semantics
        - Caching is used to store previously seen messages
        - Example: each message needed acknowledgement
    - Usage of data collection
    - Example:
        - Our messaging server has TLS/ SSL available, when in test environment, our client handshake with server
        - Where in our production we have a cluster of messaging server, behind a load balancer, and https
- Metadata Service
    - A caching layer between frontend service and persistence storage
    - Distributed Cache
        - If data present in all, load balancer
        - If not and it is sharded use consistent hash based ring
- Backend service
    - 3rd party database solution
- In Cluster Manager
    - Zookeeper
- Out Cluster manager
- Limit API Usage by amking it hard
    - Use rest endpoint for normal calls
    - Use command line commands for experienced users
- Message deletion after delivery?
    - No, keep offset, delete later by a job, used by apache kafka
    - Mark message as invisble, give client the responsiblity to call delete, if not resend
- Replication
    - Syncronous
    - Async
- Message delivery semantics
    - At most once, when lost no redelivery
    - At least once, when not lost, but redelivered, most used 
    - Exactly once, very hard to achieve
- Fifo order
    - Cant gurentee order
- Monitor
    - Dashboard setup
- Scalable
- Highly Available, Redundant
- Performant
- Durable
- Database
    - Interfaced by a facade dedicated

# Distributed Cache
- Least Recently Used
- Consistence hashing

# Design Youtube

# Top K Problem (Heavy Hitters)
- Two Data Path
    - Fast Path
        - If approx result needed then this
    - Slow path
        - Dump data in hdfs, s3
        - Run map reduce job

- Take all events
- Calculate top k
- Shrad data
- Dispatch snapshot to one
    - Merge sorted list

- Bounded data set wont work
- Streaming data needed
- Network time

- Data partioning introduces
    - Data replication
    - Rebalancing consistent hashing
    - Hot shrad

- Sacrifice accuracy
- API gateway and log counting
- Trade-off
    - No data processing on api gateway, every view sent for further processing
    - Choose compact binary format for data encode, let CPU pay the price
    - what resource availabe
        - network cpu memory disk io
    - Pre aggregate data on API gate way cluster to reduce call to kafka
    - Data partition to send data to specific cluster
    - `Process, kasfaka, partition processsor, hdfs` to slow path
    - lambda architecture

# NO-SQL Database Type
- Column
     - Cassandra: Wide column database
     - Hbase
- Document
    - MongoDB
        - Leader based relpication
- Key-Value
- Graph

Optimization Criteria
- Scalable -> Partitioning
- Reliable -> Replication / Checkpointing
- Fast -> in memory

- Is the service reliable?
- Does it has order? Arriving data more than once?


# [Gaurav Sen System Design](https://get.interviewready.io/learn/system-design-course/live_streaming_system/video_ingestion_and_transformation)
- Chess Website
    - Matching Algo to amtch players with same tier
    - Analytics - ETL Architecture
- Streaming
    - Heterogenous client


# DESIGN A UNIQUE ID GENERATOR IN DISTRIBUTED SYSTEMS
- Multi-master replication
- Universally unique identifier (UUID) 
- Ticket server
- Twitter snowflake approach
    - Devide and Conquer

# NewsFeed
- Feed publishing: When a user publishes a post, corresponding data is written into cache/database, and the post will be populated into friends’ news feed.
- Newsfeed building: The news feed is built by aggregating friends’ posts in a reverse chronological order.


# Call System Design
- IPTable
- 4 iptable entry per call
- IPtable rule not updated immediately
- [Socat](https://www.redhat.com/sysadmin/getting-started-socat)
- [Questions](https://stackoverflow.com/users/8814924/nafiul-alam-fuji)

# DESIGN CONSISTENT HASHING

# DESIGN A KEY-VALUE STORE

# DESIGN A URL SHORTENER

# Design A WEB CRAWLER

# Design a proximity server
- Finding nearby friends, uber based on distance, service open
- Show closest service point based on search query
- Scalibility vs Elasticity
- Postgres has 2d indexing
- Quad Tree
- You split it into 4 child when there is more than 100 restaurents
- Concurrent read and write when deviding into segments
- GeoHash
    - Single lat long to
- Anything in memory should be serializable
- Index on two dimension
    - Hash
        - Even grid
        - GeoHash
        - Cartesian Tiers
    - Tree
        - QuadTree
            - Any tree based is in memory not database solution
        - Google S2
        - RTree
- Granular grid for large areas and larger grids for sparse ones
    - Geohash - 5 len - 5km * 5km
    - No sharding needed 
    - Geo Index - { hash (6 bytes), business_id { 8 bytes }, lat, long { 16 bytes }}
    - 200 000000 * 30 bytes = 6 GB 

# Jordan Course
- Anti Entropy process
- CRDT
    - Change based
    - State based
- Version vectors
- When main file 
    - Sorted
        - Primary indexing, sparse indexing on primary sorted key
        - Cluster indexing
    - Not Sorted
        - Secondary index
        - Dense indexing
        - Index file always sorted
- Time Series Database
    - Column oriented
    - Encoding run length, bitmap encoding
- Graph Database
    - Index free adjacency
    - Amazon neptune
    - making io and block access optimization is the key
    - Row based, column based
- Choosing Database
    - LSM + SSTable + Bloom Filters
        - SSTable meerge and compaction strategy
            - Size Tier Compaction - Write Optimized - Cassandra
            - Leveled Compaction - Read Optimized - RocksDB
            - Summary Table to Optimize
            - Bloom filter
                - Firm no if don'y exist
                - Probably yes
        - Good write
    - B-Trees
        - Good read
    - Replication
        - Single leader
        - Multi Leader
        - Leaderless
    - SQL
        - Transactions
        - Two phase commit
    - NOSQL
        - MongoDB
            - DocumentDB
        - Cassandra
            - Wide column
        - TImestamps in ds not reliable
        - Riak
            - Key value store
        - HBase
            - Wide Column
            - Hadoop
            - Single leader
            - No write conflict
            - LSM + SSTable + Bloom Filters 
            - Column wide storage
            - Data locality
        - Graph Database
        - TimeSeries database
            - LSM + SSTable + Bloom Filters 
        - VoltDB
        - Spanner
- MMO
- Structure
    - Functional Requirements
    - Capacity Estimation
    - API Design
    - Database Schema
    - Architecral Overview
    - deep dive
- Info
    - Use UDP
    - Not just moves send states
    - Protocol buffers
    - Sharad the map, geohash
    - Region servers
    - World server communicate at
    - Lock between region servers
    - Interpolation
    - Rebalancing region servers: Consistent hashing
    - CDNs
    
# [Design Payment Gateway](https://youtu.be/shipSEFMzHs)
    - Double charge scenario tackle with idempotency
    - Good architecture setup
    - Response DB Schema
    - Black box to white box detailed, copy architecture
    - Show flow of user interactions