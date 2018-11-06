#pragma once

class BlueTooth {
  public:
    BlueTooth();
    BlueTooth(int modLine, int ctsLine, int txoLine, int rxiLine, int rtsLine);
    void run();
};

