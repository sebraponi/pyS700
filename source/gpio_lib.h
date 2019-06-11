#ifndef _GPIO_LIB_H_
#define _GPIO_LIB_H_


#define SW_PORTC_IO_BASE 0xe01b0000


#define OWL_GPIO_A	0
#define OWL_GPIO_B	1
#define OWL_GPIO_C	2
#define OWL_GPIO_D	3
#define OWL_GPIO_E	4

#define SETUP_OK            0
#define SETUP_DEVMEM_FAIL   1
#define SETUP_MALLOC_FAIL   2
#define SETUP_MMAP_FAIL     3

#define HIGH    1
#define LOW     0

#define INPUT   0
#define OUTPUT  1
#define PER     2


struct owl_gpio {
    unsigned int cfg[2];
    unsigned int dat;
//    unsigned int drv[2];
//    unsigned int pull[2];
};

/* gpio interrupt control */
struct owl_gpio_int {
    unsigned int cfg[3];
    unsigned int ctl;
    unsigned int sta;
    unsigned int deb;
};

struct owl_gpio_reg {
    struct owl_gpio gpio_bank[5];
    unsigned char res[0xbc];
    struct owl_gpio_int gpio_int;
};

#define GPIO_BANK(pin)	((pin) >> 5)
#define GPIO_NUM(pin)	((pin) & 0x1F)

#define GPIO_CFG_INDEX(pin)	(((pin) & 0x1F) >> 3)
#define GPIO_CFG_OFFSET(pin)	((pin) & 0x1F)

/* GPIO bank sizes */
#define OWL_GPIO_A_NR		(32)
#define OWL_GPIO_B_NR		(32)
#define OWL_GPIO_C_NR		(32)
#define OWL_GPIO_D_NR		(32)
#define OWL_GPIO_E_NR		(32)

#define OWL_GPIO_NEXT(__gpio) ((__gpio##_START)+(__gpio##_NR)+0)

enum owl_gpio_number {
    OWL_GPIO_A_START = 0,
    OWL_GPIO_B_START = OWL_GPIO_NEXT(OWL_GPIO_A),	//32
    OWL_GPIO_C_START = OWL_GPIO_NEXT(OWL_GPIO_B),	//64
    OWL_GPIO_D_START = OWL_GPIO_NEXT(OWL_GPIO_C),	//96
    OWL_GPIO_E_START = OWL_GPIO_NEXT(OWL_GPIO_D),	//128
};

/* OWL GPIO number definitions */
#define OWL_GPA(_nr) (OWL_GPIO_A_START + (_nr))
#define OWL_GPB(_nr) (OWL_GPIO_B_START + (_nr))
#define OWL_GPC(_nr) (OWL_GPIO_C_START + (_nr))
#define OWL_GPD(_nr) (OWL_GPIO_D_START + (_nr))
#define OWL_GPE(_nr) (OWL_GPIO_E_START + (_nr))

/* GPIO pin function config */
#define OWL_GPIO_INPUT (0)
#define OWL_GPIO_OUTPUT (1)
#define OWL_GPIO_PER (2)

#define OWL_GPA0_ERXD3 (2)
#define OWL_GPA0_SPI1_CS0 (3)
#define OWL_GPA0_UART2_RTS (4)

#define OWL_GPA1_ERXD2 (2)
#define OWL_GPA1_SPI1_CLK	(3)
#define OWL_GPA1_UART2_CTS	(4)

#define OWL_GPA2_ERXD1	(2)
#define OWL_GPA2_SPI1_MOSI	(3)
#define OWL_GPA2_UART2_TX	(4)

#define OWL_GPA10_UART1_TX	(4)
#define OWL_GPA11_UART1_RX	(4)

#define SUN4I_GPB22_UART0_TX	(2)
#define SUN4I_GPB23_UART0_RX	(2)

#define SUN5I_GPG3_UART0_TX	(4)
#define SUN5I_GPG4_UART0_RX	(4)

#define OWL_GPC2_NCLE	(2)
#define OWL_GPC2_SPI0_CLK	(3)

#define OWL_GPC6_NRB0	(2)
#define OWL_GPC6_SDC2_CMD	(3)

#define OWL_GPC7_NRB1	(2)
#define OWL_GPC7_SDC2_CLK	(3)

#define OWL_GPC8_NDQ0	(2)
#define OWL_GPC8_SDC2_D0	(3)

#define OWL_GPC9_NDQ1	(2)
#define OWL_GPC9_SDC2_D1	(3)

#define OWL_GPC10_NDQ2	(2)
#define OWL_GPC10_SDC2_D2	(3)

#define OWL_GPC11_NDQ3	(2)
#define OWL_GPC11_SDC2_D3	(3)

#define OWL_GPF2_SDC0_CLK	(2)
#define OWL_GPF2_UART0_TX	(4)

#define OWL_GPF4_SDC0_D3	(2)
#define OWL_GPF4_UART0_RX	(4)

extern int owl_gpio_input(unsigned int pin);
extern int owl_gpio_init(void);
extern int owl_gpio_set_output_cfgpin(unsigned int pin);
extern int owl_gpio_set_input_cfgpin(unsigned int pin);
extern int owl_gpio_get_cfgpin(unsigned int pin);
extern int owl_gpio_output(unsigned int pin, unsigned int val);
extern void owl_gpio_cleanup(void);

extern unsigned long int OWL_PIO_BASE;
#endif
