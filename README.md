# 9_bmp_creator_functor

## Mission
* Define BMPCreator that implements Output.

```mermaid
classDiagram
  direction LR
  class Output {
    <<interface>>
    + operator()(bool image)
  }
  class BMPCreator {
    - file
    - color
    + BMPCreator(file, color)
    + setColor(color)
    + operator()(bool image) override
  }
  Output <|.. BMPCreator
```
```c++
int main() {
  BMPCreator bmpCreator("diamond.bmp");
  bmpCreator.setColor(255, 0, 0);    // red
  PrintShape printShape([](int x, int y, int n) { return std::abs(x) + std::abs(y) < n; }, bmpCreator);
  printShape(10);

  return 0;
}
```
