# STRUKDAT_MiniProject_Bakery_System
Lina Fatima Azzahra Badr 5025251168

You are in-charge of running a popular walk-in bakery. Your team can take n amount of commands at a time, the commands contain customer orders and service operations. Every order contains an ___order number___ and a ___pastry name___. Different types of baked goods are handled using different data structures.

Orders are categorized as follows:
   - Orders for ___"macarons"___ are handled using a deque
        - If the ___order number___ is even, the order will be pushed to the front.
        - If the ___order number___ is odd, the order will be pushed to the back.
   - Orders for ___"bread"___ are handled using a queue, served in FIFO order.
   - Orders for _other pastries_ are handled using a stack, served in LIFO order.

The serving hierarchy is macarons > bread > other.

Macarons are always served before bread, and bread is always served before other pastries, regardless of the order number and when the order was placed.

Customers can also cancel their orders using their ___order number___. Cancelling an order will remove it from the data structure it is occupying.

Constraints:
- 1 <= n <= 100
- Maximum orders at a time <= 20
- 1 <= order_number <= 99
- Pastry name_length <= 100 characters
- Order numbers are not guaranteed to be unique

    Sample Input 1:
      9
      ORDER 77 creme brulee
      ORDER 12 pie
      ORDER 46 macarons
      ORDER 23 macarons
      CANCEL 12
      SERVE
      SERVE
      SERVE
      SERVE

      Sample Output 1:
      macarons 46 served!
      macarons 23 served!
      creme brulee 77 served!
      no orders to serve!
