

#include  "DATA_TYPE.h"
#include  "BIT_MATH.h"

#include  "GINT_interface.h"
#include  "GINT_private.h"

void GINT_u8_enable(void)
{
	SET_BIT(GINT_U8_STAT_REG,GINT_U8_PIN7);
}

void GINT_u8_desble(void)
{
	CLE_BIT(GINT_U8_STAT_REG,GINT_U8_PIN7);
}