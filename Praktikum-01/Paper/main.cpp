#include "Paper.hpp"
int main() {
  Paper *a = new Paper('A');
  Paper b('B');
  Paper c('C');
  Paper cc(c);
  (*a).fold();
  b.fold();
  c.fold();
  c.glue();
  delete a;
  c.setName('X');
  cc.fold();
  cc.glue();
  return 0;
}
