#include QMK_KEYBOARD_H

// Layer names
#define BASE 0
#define FN 1

// Required for leader function. Measured in ms
// #define LEADER_TIMEOUT 300

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* BASE Level: Default Layer
     |-----------+-------+------+-----+-------+-------+-------+-------+-------+-------+-------+-------+-------+------+----|
     |    Caps   |  1    | 2    | 3   |   4   |   5   |   6   | 7     | 8     | 9     | 0     | -     | =     | \    | `  |
     |-----------+-------+------+-----+-------+-------+-------+-------+-------+-------+-------+-------+-------+------+----|
     |    Tab    |  Q    | W    | E   |   R   |   T   |   Y   |  U    | I     | O     | P     | [     | ]     | Bcksp|    |
     |-----------+-------+------+-----+-------+-------+-------+-------+-------+-------+-------+-------+-------+------+----|
     |    Esc    |   A   | S    | D   |   F   |   G   |   H   |  J    | K     | L     |;      | '     | Enter |      |    |
     |-----------+-------+------+-----+-------+-------+-------+-------+-------+-------+-------+-------+-------+------+----|
     |   Shift   | Z     | X    | C   |   V   |   B   |   N   |  M    | ,     | .     | /     | Shift | Fn    |      |    |
     |-----------+-------+------+-----+-------+-------+-------+-------+-------+-------+-------+-------+-------+------+----|
                 |------+------+-----------------------+------+------|
                 | Ctrl |Super | ******* Space ******* |Super | |
                 |------+------+-----------------------+------+------|
    */

    [BASE] = LAYOUT( //  default layer
        KC_CAPS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_GRV,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC,
        KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, TG(FN),
        MO(FN), KC_LGUI, KC_SPC, KC_LCTRL, KC_LALT),

    /* Layer DEV: DEV mode (DEV Fn)
      TODO: Add a cmd/tab function to the developer layer for quick switching between different applications when debugging
      |------+-----+-----+-----+----+----+-------+----+-----+-----+------+-----+-------+-------+-----|
      |      |F1   |F2   |F3   |F4  |F5  |F6     |F7  |F8   |F9   |F10   |F11  |F12    |       |     |
      |------+-----+-----+-----+----+----+-------+----+-----+-----+------+-----+-------+-------+-----|
      |      |     |     |     |    |    |       |    |     |     |      |     |       |       |     |
      |------+-----+-----+-----+----+----+-------+----+-----+-----+------+-----+-------+-------+-----|
      |      |     |     |     |    |    |KC_LEFT|KC_DOWN|KC_UP|KC_RIGHT|      |     |       |       |     |
      |------+-----+-----+-----+----+----+-------+----+-----+-----+------+-----+-------+-------+-----|
      |      |     |     |     |    |    |       |    |     |     |      |     |       |       |     |
      |------+-----+-----+-----+----+----+-------+----+-----+-----+------+-----+-------+-------+-----|

                 |------+------+----------------------+------+------+
                 | **** | **** | ******************** | **** | **** |
                 |------+------+----------------------+------+------+
     */

    [FN] = LAYOUT(
        KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,  KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)};

