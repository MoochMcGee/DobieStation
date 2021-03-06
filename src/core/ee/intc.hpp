#ifndef INTC_HPP
#define INTC_HPP
#include <cstdint>
#include <fstream>

class EmotionEngine;

enum class Interrupt
{
    GS,
    SBUS,
    VBLANK_START,
    VBLANK_END,
    VIF0,
    VIF1,
    VU0,
    VU1,
    IPU,
    TIMER0,
    TIMER1,
    TIMER2,
    TIMER3,
    SFIFO,
    VU0_WATCHDOG //bark
};

class INTC
{
    private:
        EmotionEngine* cpu;
        uint32_t INTC_MASK, INTC_STAT;

        void int0_check();
    public:
        INTC(EmotionEngine* cpu);

        void reset();

        uint32_t read_mask();
        uint32_t read_stat();
        void write_mask(uint32_t value);
        void write_stat(uint32_t value);

        void assert_IRQ(int id);
        void deassert_IRQ(int id);

        void load_state(std::ifstream& state);
        void save_state(std::ofstream& state);
};

#endif // INTC_HPP
