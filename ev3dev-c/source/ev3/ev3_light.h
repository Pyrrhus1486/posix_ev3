
/*  ev3_light.h was generated by yup.py (yupp) 1.0b4
    out of ev3_light.yu-h 
 *//**
 *  \file  ev3_light.h (ev3_light.yu-h)
 *  \brief  EV3 Lights (GREEN and RED LEDs at once).
 *  \author  Vitaly Kravtsov (in4lio@gmail.com)
 *  \copyright  See the LICENSE file.
 */

#ifndef EV3_LIGHT_H
#define EV3_LIGHT_H

#ifdef  EV3_LIGHT_IMPLEMENT
#define EV3_LIGHT_EXT
#define EV3_LIGHT_EXT_INIT( dec, init ) \
	dec = init
#define EV3_LIGHT_EXT_C
#define EV3_LIGHT_EXT_C_INIT( dec, init ) \
	dec = init
#define EV3_LIGHT_INL
#else
#define EV3_LIGHT_EXT extern
#define EV3_LIGHT_EXT_INIT( dec, init ) \
	extern dec
#ifdef __cplusplus
#define EV3_LIGHT_C "C"
#else
#define EV3_LIGHT_C
#endif
#define EV3_LIGHT_EXT_C extern EV3_LIGHT_C
#define EV3_LIGHT_EXT_C_INIT( dec, init ) \
	extern EV3_LIGHT_C dec
#if __GNUC__ && !__GNUC_STDC_INLINE__
#define EV3_LIGHT_INL extern inline
#else
#define EV3_LIGHT_INL inline
#endif
#endif

#ifndef COMMA
#define COMMA ,
#endif

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

/**
 *  \defgroup ev3_light Lights
 *  \brief Access to EV3 GREEN and RED LEDs at once.
 *  \{
 */

/**
 *  \brief Identifiers of light locations.
 */
enum {
	LIT_LEFT,
	LIT_RIGHT,

	LIT__LOC__
};

/**
 *  \brief Identifiers of light colors.
 */
enum {
	LIT_OFF,
	LIT_GREEN,
	LIT_RED,
	LIT_AMBER,

	LIT__COL__
};

/**
 *  \brief Light colors.
 */
EV3_LIGHT_EXT_C_INIT( const char *const LIT_COLOR[], { "OFF" COMMA  "GREEN" COMMA  "RED" COMMA  "AMBER" COMMA  STR_unknown_ } );

/**
 *  \brief Get the light color name.
 *  \param col Color.
 *  \return Color name.
 */
EV3_LIGHT_EXT_C const char *light_color( uint8_t col );

/**
 *  \brief Set the light color.
 *  \param loc Location.
 *  \param col Color.
 */
EV3_LIGHT_EXT_C void set_light( uint8_t loc, uint8_t col );

/**
 *  \brief Get the light color.
 *  \param loc Location.
 *  \return Color.
 */
EV3_LIGHT_EXT_C uint8_t get_light( uint8_t loc );

/**
 *  \brief Set the light trigger.
 *  \param loc Location.
 *  \param col Color.
 *  \param trigger Index of trigger.
 */
EV3_LIGHT_EXT_C void set_light_trigger( uint8_t loc, uint8_t col, uint8_t trigger );

/**
 *  \brief Get the light trigger.
 *  \param loc Location.
 *  \param col Color.
 *  \return Index of trigger or TRIGGER__COUNT_ - error has occurred.
 */
EV3_LIGHT_EXT_C uint8_t get_light_trigger( uint8_t loc, uint8_t col );

/**
 *  \brief Set the light blink.
 *  \param loc Location.
 *  \param col Color.
 *  \param delay_on Time of "on" state in ms.
 *  \param delay_off Time of "off" state in ms.
 */
EV3_LIGHT_EXT_C void set_light_blink( uint8_t loc, uint8_t col, int delay_on, int delay_off );

/**
 *  \brief Check the light is blinking.
 *  \param loc Location.
 *  \param col Color.
 *  \return Flag - the light is blinking.
 */
EV3_LIGHT_EXT_C bool get_light_blink( uint8_t loc, uint8_t col );

/** \} */

#undef EV3_LIGHT_EXT
#undef EV3_LIGHT_EXT_INIT
#undef EV3_LIGHT_EXT_C
#undef EV3_LIGHT_EXT_C_INIT
#undef EV3_LIGHT_INL
#undef EV3_LIGHT_C
#endif
