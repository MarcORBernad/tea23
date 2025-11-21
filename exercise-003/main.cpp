#include <fmt/chrono.h>
#include <fmt/format.h>

typedef enum
{
    OBEN = 0,
    UNTEN = 1,
    HOCH = 2,
    RUNTER = 3,
    STOP_HOCH = 4,
    STOP_RUNTER = 5,
    ERROR = 6
} States;

typedef enum
{
    TASTE = 0,
    ES_OBEN = 1,
    ES_UNTEN = 2
} Events;

/*
   Vollständige Tabelle (Events × States)

   Regeln:
   • STOP_HOCH und STOP_RUNTER bleiben stehen, bis Endschalter kommt.
   • ERROR bleibt immer ERROR.
   • Für alle nicht definierten Kombinationen wird ein sicherer Zustand gewählt.
*/

static const States state_table[3][7] =
{
    /* TASTE */
    {
        RUNTER,     // OBEN
        HOCH,       // UNTEN
        STOP_HOCH,  // HOCH
        STOP_RUNTER,// RUNTER
        HOCH,       // STOP_HOCH
        RUNTER,     // STOP_RUNTER
        ERROR       // ERROR
    },

    /* ES_OBEN */
    {
        OBEN,       // OBEN
        ERROR,      // UNTEN
        OBEN,       // HOCH
        ERROR,      // RUNTER
        OBEN,       // STOP_HOCH
        ERROR,      // STOP_RUNTER
        ERROR       // ERROR
    },

    /* ES_UNTEN */
    {
        ERROR,      // OBEN
        UNTEN,      // UNTEN
        ERROR,      // HOCH
        UNTEN,      // RUNTER
        ERROR,      // STOP_HOCH
        UNTEN,      // STOP_RUNTER
        ERROR       // ERROR
    }
};

States next_state(States current, Events ev)
{
    if (ev > ES_UNTEN || current > ERROR)
        return ERROR;

    return state_table[ev][current];
}

auto main(int argc, char** argv) -> int
{
    States s = HOCH;
    s = next_state(s, TASTE);
    fmt::print("Neuer Zustand: {}\n", s);

    return 0;
}
