https://leetcode.com/discuss/interview-question/system-design/220073/How-would-you-design-WhatsApp

https://leetcode.com/discuss/interview-question/system-design/124803/Design-BookMyShow

https://leetcode.com/discuss/interview-question/system-design/733520/Design-YouTube-Very-detailed-design-with-diagrams

https://leetcode.com/discuss/interview-question/system-design/125751/Design-a-distributed-cache-system

https://leetcode.com/discuss/interview-question/system-design/124804/Design-Pastebin

- [Web Crawler](
https://leetcode.com/discuss/interview-question/system-design/548816/Amazon-or-System-Design-or-Web-Crawler-Detector)
    - add a few hidden href in your page with display:None. 
    - Only bots or curious people would hit those pages and if enough of them were hit, you would detect a candidate bot.
    - a distributed lookup table for "IP -> # of requests from that IP over last 60 secs
    - 100+ requests from a single IP within a minute
    - Crawler trap

### System Design

𝟭) 𝗕𝗟𝗢𝗢𝗠 𝗙𝗜𝗟𝗧𝗘𝗥
It is a data structure designed to tell you, rapidly and memory-efficiently, whether an element is present in a set.
𝙐𝙨𝙚 𝙘𝙖𝙨𝙚: Build a Web crawler

𝟮) 𝗙𝗥𝗨𝗚𝗔𝗟 𝗦𝗧𝗥𝗘𝗔𝗠𝗜𝗡𝗚
It uses only one unit of memory per group to compute a quantile for each group.
𝙐𝙨𝙚 𝙘𝙖𝙨𝙚: Find the nth percentile of the data stream.

𝟯) 𝗚𝗘𝗢𝗛𝗔𝗦𝗛/ 𝗦𝟮 𝗚𝗘𝗢𝗠𝗘𝗧𝗥𝗬
A collection of efficient yet exact mathematical predicates for testing relationships among geometric primitives.
𝙐𝙨𝙚 𝙘𝙖𝙨𝙚:Location-based search results with DynamoDb and Geohash.

𝟰) 𝗛𝗬𝗣𝗘𝗥𝗟𝗢𝗚𝗟𝗢𝗚
It is an algorithm for the count-distinct problem, approximating the number of distinct elements in a multiset.
𝙐𝙨𝙚 𝙘𝙖𝙨𝙚: privacy-preserving traffic heat map for the city.

𝟱) 𝗟𝗘𝗔𝗞𝗬 𝗕𝗨𝗖𝗞𝗘𝗧/ 𝗧𝗢𝗞𝗘𝗡 𝗕𝗨𝗖𝗞𝗘𝗧
A mechanism to control the amount and the rate of the traffic sent to the network.
𝙐𝙨𝙚 𝙘𝙖𝙨𝙚: Design a scalable rate-limiting algorithm.

𝟲) 𝗟𝗢𝗦𝗦𝗬 𝗖𝗢𝗨𝗡𝗧
It is used to identify elements in a data stream whose frequency count exceeds a user-given threshold.
𝙐𝙨𝙚 𝙘𝙖𝙨𝙚: Frequency count over the data streams.

𝟳) 𝗢𝗣𝗘𝗥𝗔𝗧𝗜𝗢𝗡𝗔𝗟 𝗧𝗥𝗔𝗡𝗦𝗙𝗢𝗥𝗠𝗔𝗧𝗜𝗢𝗡
It is used for supporting a range of collaboration functionalities in advanced collaborative software systems.
𝙐𝙨𝙚 𝙘𝙖𝙨𝙚: Handling editing collision in Google docs.

𝟴) 𝗤𝗨𝗔𝗗𝗧𝗥𝗘𝗘/ 𝗥𝗧𝗥𝗘𝗘
It is a two-dimensional analog of octrees and is most often used to partition a two-dimensional space by recursively subdividing it into four quadrants or regions.
𝙐𝙨𝙚 𝙘𝙖𝙨𝙚: find nearby interest points

𝟵) 𝗥𝗔𝗬 𝗖𝗔𝗦𝗧𝗜𝗡𝗚
It is the most basic of many computer graphics rendering algo that uses geometric algo of ray tracing.
𝙐𝙨𝙚 𝙘𝙖𝙨𝙚: using longitude and latitude, return the Country of the point.

𝟭𝟬) 𝗥𝗘𝗩𝗘𝗥𝗦𝗘 𝗜𝗡𝗗𝗘𝗫
It is an index of keywords that stores records of documents that contain keywords in the list.
𝙐𝙨𝙚 𝙘𝙖𝙨𝙚: Create a complete Tweet index.

𝟭𝟭) 𝗥𝗦𝗬𝗡𝗖 𝗔𝗟𝗚𝗢𝗥𝗜𝗧𝗛𝗠
Used for reducing the cost of a file transfer by avoiding the transfer of blocks that are already at the destination.
𝙐𝙨𝙚 𝙘𝙖𝙨𝙚:: Streaming file Sync

# [InterviewReady](https://get.interviewready.io/learn/system-design-course/how-do-i-use-this-course/course-walkthrough)


# Framework

(1) FEATURE EXPECTATIONS [5 min]
        (1) Use cases
        (2) Scenarios that will not be covered
        (3) Who will use
        (4) How many will use
        (5) Usage patterns
(2) ESTIMATIONS [5 min]
        (1) Throughput (QPS for read and write queries)
        (2) Latency expected from the system (for read and write queries)
        (3) Read/Write ratio
        (4) Traffic estimates
                - Write (QPS, Volume of data)
                - Read  (QPS, Volume of data)
        (5) Storage estimates
        (6) Memory estimates
                - If we are using a cache, what is the kind of data we want to store in cache
                - How much RAM and how many machines do we need for us to achieve this ?
                - Amount of data you want to store in disk/ssd
(3) DESIGN GOALS [5 min]
        (1) Latency and Throughput requirements
        (2) Consistency vs Availability  [Weak/strong/eventual => consistency | Failover/replication => availability]
(4) HIGH LEVEL DESIGN [5-10 min]
        (1) APIs for Read/Write scenarios for crucial components
        (2) Database schema
        (3) Basic algorithm
        (4) High level design for Read/Write scenario
(5) DEEP DIVE [15-20 min]
        (1) Scaling the algorithm
        (2) Scaling individual components: 
                -> Availability, Consistency and Scale story for each component
                -> Consistency and availability patterns
        (3) Think about the following components, how they would fit in and how it would help
                a) DNS
                b) CDN [Push vs Pull]
                c) Load Balancers [Active-Passive, Active-Active, Layer 4, Layer 7]
                d) Reverse Proxy
                e) Application layer scaling [Microservices, Service Discovery]
                f) DB [RDBMS, NoSQL]
                        > RDBMS 
                            >> Master-slave, Master-master, Federation, Sharding, Denormalization, SQL Tuning
                        > NoSQL
                            >> Key-Value, Wide-Column, Graph, Document
                                Fast-lookups:
                                -------------
                                    >>> RAM  [Bounded size] => Redis, Memcached
                                    >>> AP [Unbounded size] => Cassandra, RIAK, Voldemort
                                    >>> CP [Unbounded size] => HBase, MongoDB, Couchbase, DynamoDB
                g) Caches
                        > Client caching, CDN caching, Webserver caching, Database caching, Application caching, Cache @Query level, Cache @Object level
                        > Eviction policies:
                                >> Cache aside
                                >> Write through
                                >> Write behind
                                >> Refresh ahead
                h) Asynchronism
                        > Message queues
                        > Task queues
                        > Back pressure
                i) Communication
                        > TCP
                        > UDP
                        > REST
                        > RPC
(6) JUSTIFY [5 min]
	(1) Throughput of each layer
	(2) Latency caused between each layer
	(3) Overall latency justification