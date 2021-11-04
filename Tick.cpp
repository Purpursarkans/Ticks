#include <bits/stdc++.h>
#include <windows.h>

#define TICK_TIME 500

class Timer
{
private:
    // Псевдонимы типов используются для удобного доступа к вложенным типам
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<long, std::milli>;

    std::chrono::time_point<clock_t> m_beg;

public:
    Timer() : m_beg(clock_t::now())
    {
    }

    void reset()
    {
        m_beg = clock_t::now();
    }

    long elapsed() const
    {
        return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }
};

void Tick()
{
    Timer timer;
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::cout << "Time elapsed: " << timer.elapsed() << '\n';
}

void beep()
{
    Beep(666,200);
}

void Print()
{
    std::cout << "Print" << std::endl;
}

void Print2()
{
    std::cout << "Print2" << std::endl;
}

int main()
{
    Timer timer;
    while(0)
    {
        std::cout << "Time elapsed1: " << timer.elapsed() << '\n';
        if (timer.elapsed() < TICK_TIME)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(TICK_TIME - timer.elapsed()));
            
        }
        if (timer.elapsed() > TICK_TIME)
        {
            
            std::cout << "TICK" << std::endl;
            std::cout << "Time elapsed2: " << timer.elapsed() << '\n';
            timer.reset();
        }
    }

    for(int i = 0; i < 1; ++i)
    {
        std::thread _beep(beep);
        std::thread _Print(Print);
        std::thread _Print2(Print2);
        std::cout << "main thread-----------" << std::endl;
        _beep.join();
        _Print.join();
        _Print2.join();
    }

    std::cout << "Programm time: " << timer.elapsed() << '\n';
    system("pause");
}