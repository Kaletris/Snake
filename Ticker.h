#ifndef MAIN_CPP_TICKER_H
#define MAIN_CPP_TICKER_H

class Ticker{
    int szamlalo;
    int ticks;
public:
    Ticker(int speed = 1, int szamlalo = 1000) : szamlalo(szamlalo), ticks(1000 / (speed * 10)){};
    Ticker(const Ticker& ticker) : szamlalo(ticker.szamlalo), ticks(ticker.ticks){};
    ~Ticker(){};

    void tick();

};

#endif //MAIN_CPP_TICKER_H
