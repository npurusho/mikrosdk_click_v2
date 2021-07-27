/*!
 * @file main.c
 * @brief UT-L7-SEGR Click example
 *
 * # Description
 * The demo application shows basic usage of the UT 7 SEG display.
 *
 * The demo application is composed of two sections :
 * 
 * ## Application Init 
 * Configuring clicks and log objects.
 * Settings the click in the default configuration.
 * 
 * ## Application Task  
 * Draws numbers from 0 to 99 on the screen.
 * 
 * @author Stefan Ilic
 *
 */

#include "board.h"
#include "log.h"
#include "utl7segr.h"

static utl7segr_t utl7segr;
static log_t logger;

void application_init ( void ) {
    log_cfg_t log_cfg;            /**< Logger config object. */
    utl7segr_cfg_t utl7segr_cfg;  /**< Click config object.  */

    // Logger initialization.

    LOG_MAP_USB_UART( log_cfg );
    log_cfg.level = LOG_LEVEL_DEBUG;
    log_cfg.baud = 115200;
    log_init( &logger, &log_cfg );
    log_info( &logger, "---- Application Init ----" );

    // Click initialization.

    utl7segr_cfg_setup( &utl7segr_cfg );
    UTL7SEGR_MAP_MIKROBUS( utl7segr_cfg, MIKROBUS_1 );
    err_t init_flag  = utl7segr_init( &utl7segr, &utl7segr_cfg );
    if ( init_flag == SPI_MASTER_ERROR ) {
        log_error( &logger, " Application Init Error. " );
        log_info( &logger, " Please, run program again... " );

        for ( ; ; );
    }

    utl7segr_default_cfg ( &utl7segr );
    log_info( &logger, " Application Task " );
}

void application_task ( void ) {  
    log_info( &logger, "---- Number counter ----" );

    for ( uint8_t cnt = 0; cnt < 100; cnt++ ) {
        utl7segr_display_number( &utl7segr, cnt, UTL7SEGR_DOT_LEFT );
        Delay_ms( 500 );
    }
}

void main ( void ) {
    application_init( );

    for ( ; ; ) {
        application_task( );
    }
}

// ------------------------------------------------------------------------ END
