# 10_image_shape

## Mission
* Define Image to extend Shape with Boolean image.
* Define BMP to extend Image.

```mermaid
classDiagram
  direction LR
  class Shape {
    + inside(x, y, size) bool
  }
  class Image {
    + Image(bool_image)
    + inside(x, y, size) bool
    + getSize() int
  }
  class BMP {
    BMP(file)
  }
  Shape <|-- Image
  Image <|-- BMP
```
```c++
int main() {
  BMP bmp("diamond.bmp");
  StreamOut streamOut;
  PrintShape pritnShape(bmp, streamOut);
  printShape(bmp.getSize());

  return 0;
}
```
