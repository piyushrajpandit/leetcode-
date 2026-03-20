# Design Circular Deque (LeetCode 641) – Approach Notes

## 1. Insert Front

**Step 1: Check if Full**

```
(front == 0 && rear == size - 1) || (rear == (front - 1 + size) % size)
```

**Step 2: If first element**

```
if (front == -1) {
    front = rear = 0;
}
```

**Step 3: Maintain cyclic nature**

```
else if (front == 0 && rear != size - 1) {
    front = size - 1;
}
```

**Step 4: Normal case**

```
else {
    front = front - 1;
}
```

---

## 2. Insert Rear

**Step 1: Check if Full**

```
(front == 0 && rear == size - 1) || (rear == (front - 1 + size) % size)
```

**Step 2: If first element**

```
if (front == -1) {
    front = rear = 0;
}
```

**Step 3: Maintain cyclic nature**

```
else if (rear == size - 1 && front != 0) {
    rear = 0;
}
```

**Step 4: Normal case**

```
else {
    rear = rear + 1;
}
```

---

## 3. Delete Last

**Step 1: Check if Empty**

```
front == -1
```

**Step 2: If only one element**

```
if (front == rear) {
    front = rear = -1;
}
```

**Step 3: Maintain cyclic nature**

```
else if (rear == 0) {
    rear = size - 1;
}
```

**Step 4: Normal case**

```
else {
    rear = rear - 1;
}
```

---

## 4. Delete Front

**Step 1: Check if Empty**

```
front == -1
```

**Step 2: If only one element**

```
if (front == rear) {
    front = rear = -1;
}
```

**Step 3: Maintain cyclic nature**

```
else if (front == size - 1) {
    front = 0;
}
```

**Step 4: Normal case**

```
else {
    front = front + 1;
}
```
