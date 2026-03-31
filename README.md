# STRUKDAT_MiniProject_Bakery_System
Lina Fatima Azzahra Badr 5025251168

You are in-charge of running a popular walk-in bakery. Your team can take n amount of commands at a time, the commands contain customer orders and service operations. Every order contains an ___order number___ and a ___pastry name___. Different types of baked goods are handled using different data structures.

Orders are categorized as follows:
   - Orders for ___"macarons"___ are handled using a deque
        - If the ___order number___ is even, the order will be pushed to the front.
        - If the ___order number___ is odd, the order will be pushed to the back.
   - Orders for ___"bread"___ are handled using a queue, served in FIFO order.
   - Orders for __other pastries__ are handled using a stack, served in LIFO order.

The serving hierarchy is macarons > bread > other.

Macarons are always served before bread, and bread is always served before other pastries, regardless of the order number and when the order was placed.

Customers can also cancel their orders using their ___order number___. Cancelling an order will remove it from the data structure it is occupying.

### Constraints:
- 1 <= n <= 100
- Maximum orders at a time <= 20
- 1 <= order_number <= 99
- Pastry name_length <= 100 characters
- Order numbers are not guaranteed to be unique



### Sample Input 1
```
10
ORDER 91 croissant
ORDER 24 bread
ORDER 44 macarons
ORDER 15 cake
ORDER 31 macarons
SERVE
SERVE
SERVE
SERVE
SERVE
```
### Sample Output 1
```
macarons 44 served!
macarons 31 served!
bread 24 served!
cake 15 served!
croissant 91 served!
```


### Sample Input 2
```
5
ORDER 21 bread
ORDER 17 pie
CANCEL 21
SERVE
SERVE
```
### Sample Output 2
```
pie 17 served!
no orders to serve!
```
