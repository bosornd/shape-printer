# 5_stream_out_functor

## Mission
* Separate the output method from the PrintShape class.
* Design the output method to be independently extensible.

```mermaid
classDiagram
  direction RL
  class PrintShape {
    - insideShape
    - output
    + PrintShape(insideShape, output)
    + setOutput(output)
    + operator()(size)
  }
  class Output {
    <<interface>>
    + operator()(bool image)
  }
  class StreamOut {
    - output
    - characters
    + StreamOut(output, characters)
    + setOutput(output)
    + setCharacters(characters)
    + operator()(bool image) override
  }
  Output <|.. StreamOut
  PrintShape --> Output
```
```c++
int main() {
    StreamOut streamOut;
    std::ofstream file("diamond.txt");
    StreamOut.setOutput(file);
    StreamOut.setCharacters("O", ".");

    PrintShape printShape([](int x, int y, int n) { return std::abs(x) + std::abs(y) < n; }, streamOut);
    printShape(10);

    return 0;
}
```
