
---
# Keylock click

Keylock click carries a processed sealed key lock mechanism that can be set in three different positions. The click is designed to run on either 3.3V or 5V power supply. 

<p align="center">
  <img src="https://download.mikroe.com/images/click_for_ide/keylock_click.png" height=300px>
</p>

[click Product page](https://www.mikroe.com/keylock-click)

---


#### Click library 

- **Author**        : MikroE Team
- **Date**          : Dec 2019.
- **Type**          : GPIO type


# Software Support

We provide a library for the Keylock Click 
as well as a demo application (example), developed using MikroElektronika 
[compilers](https://shop.mikroe.com/compilers). 
The demo can run on all the main MikroElektronika [development boards](https://shop.mikroe.com/development-boards).

Package can be downloaded/installed directly form compilers IDE(recommended way), or downloaded from our LibStock, or found on mikroE github account. 

## Library Description

> This library contains API for Keylock Click driver.

#### Standard key functions :

- Config Object Initialization function.
> void keylock_cfg_setup ( keylock_cfg_t *cfg ); 
 
- Initialization function.
> KEYLOCK_RETVAL keylock_init ( keylock_t *ctx, keylock_cfg_t *cfg );

#### Example key functions :

- Checks pin state.
> uint8_t keylock_check_pin ( keylock_t *ctx, uint8_t pin );
 
- Gets key position.
> uint8_t keylock_get_position ( keylock_t *ctx );

## Examples Description

> This application monitors key position in its lock mechanism.

**The demo application is composed of two sections :**

### Application Init 

> Initialization driver enables GPIO and also writes log.

```c

void application_init ( void )
{
    log_cfg_t log_cfg;
    keylock_cfg_t cfg;

    //  Logger initialization.

    log_cfg.level = LOG_LEVEL_DEBUG;
    LOG_MAP_USB_UART( log_cfg );
    log_init( &logger, &log_cfg );
    log_info(&logger, "---- Application Init ----");

    //  Click initialization.

    keylock_cfg_setup( &cfg );
    KEYLOCK_MAP_MIKROBUS( cfg, MIKROBUS_1 );
    keylock_init( &keylock, &cfg );
    Delay_ms( 100 );
    log_printf( &logger, "--------------- \r\n" );
    log_printf( &logger, " Keylock Click \r\n" );
    log_printf( &logger, "--------------- \r\n" );
}
  
```

### Application Task

> Detects the position in which the key currently is.
  Results are being sent to the Terminal, where you can track changes.

```c

void application_task ( void )
{
    uint8_t new_state;
    uint8_t old_state = 0;

    new_state = keylock_get_position( &keylock );

    if ( old_state != new_state )
    {
        if ( new_state == KEYLOCK_KEY_POS_1 )
        {
            log_printf( &logger, " Position ONE \r\n" );
        }
        else if ( new_state == KEYLOCK_KEY_POS_2 )
        {
            log_printf( &logger, " Position TWO \r\n" );
        }
        else if ( new_state == KEYLOCK_KEY_POS_3 )
        {
            log_printf( &logger, " Position THREE \r\n" );
        }
        else
        {
            log_printf( &logger, " ERROR!!! \r\n" );
        }
    old_state = new_state;
    log_printf( &logger, "---------------- \r\n" );
    }

    Delay_ms( 500 );
}  

```

## Note

The full application code, and ready to use projects can be  installed directly form compilers IDE(recommneded) or found on LibStock page or mikroE GitHub accaunt.

**Other mikroE Libraries used in the example:** 

- MikroSDK.Board
- MikroSDK.Log
- Click.Keylock

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](https://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](https://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](https://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](https://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.


---
