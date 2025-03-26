# 1_print_shape_using_inside_shape

## Mission
* Define printShape function that print a shape using the given insideShape function.
* Define insideDiamond function.

```c++
void printShape(int n, std::function<bool(int, int, int)> insideShape);
bool insideDiamond(int x, int y, int n);

int main() {
    printShape(3, insideDiamond);
    return 0;
}
```
