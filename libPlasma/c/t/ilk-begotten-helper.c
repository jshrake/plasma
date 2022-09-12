
/* (c)  oblong industries */

#include "ilk-begotten-helper.h"
#include "libPlasma/c/pool.h"

typedef bool (*SlawTypePredicate) (bslaw s);

typedef struct
{
  SlawTypePredicate slawTypePredicate;
  const char *slawTypeName;
} SlawTypePredicateAndName;

const SlawTypePredicateAndName gSlawTypePredicateAndNames[] =
  {{&slaw_is_int32, "int32"},
   {&slaw_is_int32_array, "int32_array"},
   {&slaw_is_unt32, "unt32"},
   {&slaw_is_unt32_array, "unt32_array"},
   {&slaw_is_int64, "int64"},
   {&slaw_is_int64_array, "int64_array"},
   {&slaw_is_unt64, "unt64"},
   {&slaw_is_unt64_array, "unt64_array"},
   {&slaw_is_float32, "float32"},
   {&slaw_is_float32_array, "float32_array"},
   {&slaw_is_float64, "float64"},
   {&slaw_is_float64_array, "float64_array"},
   {&slaw_is_int8, "int8"},
   {&slaw_is_int8_array, "int8_array"},
   {&slaw_is_unt8, "unt8"},
   {&slaw_is_unt8_array, "unt8_array"},
   {&slaw_is_int16, "int16"},
   {&slaw_is_int16_array, "int16_array"},
   {&slaw_is_unt16, "unt16"},
   {&slaw_is_unt16_array, "unt16_array"},
   {&slaw_is_int32c, "int32c"},
   {&slaw_is_int32c_array, "int32c_array"},
   {&slaw_is_unt32c, "unt32c"},
   {&slaw_is_unt32c_array, "unt32c_array"},
   {&slaw_is_int64c, "int64c"},
   {&slaw_is_int64c_array, "int64c_array"},
   {&slaw_is_unt64c, "unt64c"},
   {&slaw_is_unt64c_array, "unt64c_array"},
   {&slaw_is_float32c, "float32c"},
   {&slaw_is_float32c_array, "float32c_array"},
   {&slaw_is_float64c, "float64c"},
   {&slaw_is_float64c_array, "float64c_array"},
   {&slaw_is_int8c, "int8c"},
   {&slaw_is_int8c_array, "int8c_array"},
   {&slaw_is_unt8c, "unt8c"},
   {&slaw_is_unt8c_array, "unt8c_array"},
   {&slaw_is_int16c, "int16c"},
   {&slaw_is_int16c_array, "int16c_array"},
   {&slaw_is_unt16c, "unt16c"},
   {&slaw_is_unt16c_array, "unt16c_array"},
   {&slaw_is_v2int32, "v2int32"},
   {&slaw_is_v2int32_array, "v2int32_array"},
   {&slaw_is_v2unt32, "v2unt32"},
   {&slaw_is_v2unt32_array, "v2unt32_array"},
   {&slaw_is_v2int64, "v2int64"},
   {&slaw_is_v2int64_array, "v2int64_array"},
   {&slaw_is_v2unt64, "v2unt64"},
   {&slaw_is_v2unt64_array, "v2unt64_array"},
   {&slaw_is_v2float32, "v2float32"},
   {&slaw_is_v2float32_array, "v2float32_array"},
   {&slaw_is_v2float64, "v2float64"},
   {&slaw_is_v2float64_array, "v2float64_array"},
   {&slaw_is_v2int8, "v2int8"},
   {&slaw_is_v2int8_array, "v2int8_array"},
   {&slaw_is_v2unt8, "v2unt8"},
   {&slaw_is_v2unt8_array, "v2unt8_array"},
   {&slaw_is_v2int16, "v2int16"},
   {&slaw_is_v2int16_array, "v2int16_array"},
   {&slaw_is_v2unt16, "v2unt16"},
   {&slaw_is_v2unt16_array, "v2unt16_array"},
   {&slaw_is_v3int32, "v3int32"},
   {&slaw_is_v3int32_array, "v3int32_array"},
   {&slaw_is_v3unt32, "v3unt32"},
   {&slaw_is_v3unt32_array, "v3unt32_array"},
   {&slaw_is_v3int64, "v3int64"},
   {&slaw_is_v3int64_array, "v3int64_array"},
   {&slaw_is_v3unt64, "v3unt64"},
   {&slaw_is_v3unt64_array, "v3unt64_array"},
   {&slaw_is_v3float32, "v3float32"},
   {&slaw_is_v3float32_array, "v3float32_array"},
   {&slaw_is_v3float64, "v3float64"},
   {&slaw_is_v3float64_array, "v3float64_array"},
   {&slaw_is_v3int8, "v3int8"},
   {&slaw_is_v3int8_array, "v3int8_array"},
   {&slaw_is_v3unt8, "v3unt8"},
   {&slaw_is_v3unt8_array, "v3unt8_array"},
   {&slaw_is_v3int16, "v3int16"},
   {&slaw_is_v3int16_array, "v3int16_array"},
   {&slaw_is_v3unt16, "v3unt16"},
   {&slaw_is_v3unt16_array, "v3unt16_array"},
   {&slaw_is_v4int32, "v4int32"},
   {&slaw_is_v4int32_array, "v4int32_array"},
   {&slaw_is_v4unt32, "v4unt32"},
   {&slaw_is_v4unt32_array, "v4unt32_array"},
   {&slaw_is_v4int64, "v4int64"},
   {&slaw_is_v4int64_array, "v4int64_array"},
   {&slaw_is_v4unt64, "v4unt64"},
   {&slaw_is_v4unt64_array, "v4unt64_array"},
   {&slaw_is_v4float32, "v4float32"},
   {&slaw_is_v4float32_array, "v4float32_array"},
   {&slaw_is_v4float64, "v4float64"},
   {&slaw_is_v4float64_array, "v4float64_array"},
   {&slaw_is_v4int8, "v4int8"},
   {&slaw_is_v4int8_array, "v4int8_array"},
   {&slaw_is_v4unt8, "v4unt8"},
   {&slaw_is_v4unt8_array, "v4unt8_array"},
   {&slaw_is_v4int16, "v4int16"},
   {&slaw_is_v4int16_array, "v4int16_array"},
   {&slaw_is_v4unt16, "v4unt16"},
   {&slaw_is_v4unt16_array, "v4unt16_array"},
   {&slaw_is_v2int32c, "v2int32c"},
   {&slaw_is_v2int32c_array, "v2int32c_array"},
   {&slaw_is_v2unt32c, "v2unt32c"},
   {&slaw_is_v2unt32c_array, "v2unt32c_array"},
   {&slaw_is_v2int64c, "v2int64c"},
   {&slaw_is_v2int64c_array, "v2int64c_array"},
   {&slaw_is_v2unt64c, "v2unt64c"},
   {&slaw_is_v2unt64c_array, "v2unt64c_array"},
   {&slaw_is_v2float32c, "v2float32c"},
   {&slaw_is_v2float32c_array, "v2float32c_array"},
   {&slaw_is_v2float64c, "v2float64c"},
   {&slaw_is_v2float64c_array, "v2float64c_array"},
   {&slaw_is_v2int8c, "v2int8c"},
   {&slaw_is_v2int8c_array, "v2int8c_array"},
   {&slaw_is_v2unt8c, "v2unt8c"},
   {&slaw_is_v2unt8c_array, "v2unt8c_array"},
   {&slaw_is_v2int16c, "v2int16c"},
   {&slaw_is_v2int16c_array, "v2int16c_array"},
   {&slaw_is_v2unt16c, "v2unt16c"},
   {&slaw_is_v2unt16c_array, "v2unt16c_array"},
   {&slaw_is_v3int32c, "v3int32c"},
   {&slaw_is_v3int32c_array, "v3int32c_array"},
   {&slaw_is_v3unt32c, "v3unt32c"},
   {&slaw_is_v3unt32c_array, "v3unt32c_array"},
   {&slaw_is_v3int64c, "v3int64c"},
   {&slaw_is_v3int64c_array, "v3int64c_array"},
   {&slaw_is_v3unt64c, "v3unt64c"},
   {&slaw_is_v3unt64c_array, "v3unt64c_array"},
   {&slaw_is_v3float32c, "v3float32c"},
   {&slaw_is_v3float32c_array, "v3float32c_array"},
   {&slaw_is_v3float64c, "v3float64c"},
   {&slaw_is_v3float64c_array, "v3float64c_array"},
   {&slaw_is_v3int8c, "v3int8c"},
   {&slaw_is_v3int8c_array, "v3int8c_array"},
   {&slaw_is_v3unt8c, "v3unt8c"},
   {&slaw_is_v3unt8c_array, "v3unt8c_array"},
   {&slaw_is_v3int16c, "v3int16c"},
   {&slaw_is_v3int16c_array, "v3int16c_array"},
   {&slaw_is_v3unt16c, "v3unt16c"},
   {&slaw_is_v3unt16c_array, "v3unt16c_array"},
   {&slaw_is_v4int32c, "v4int32c"},
   {&slaw_is_v4int32c_array, "v4int32c_array"},
   {&slaw_is_v4unt32c, "v4unt32c"},
   {&slaw_is_v4unt32c_array, "v4unt32c_array"},
   {&slaw_is_v4int64c, "v4int64c"},
   {&slaw_is_v4int64c_array, "v4int64c_array"},
   {&slaw_is_v4unt64c, "v4unt64c"},
   {&slaw_is_v4unt64c_array, "v4unt64c_array"},
   {&slaw_is_v4float32c, "v4float32c"},
   {&slaw_is_v4float32c_array, "v4float32c_array"},
   {&slaw_is_v4float64c, "v4float64c"},
   {&slaw_is_v4float64c_array, "v4float64c_array"},
   {&slaw_is_v4int8c, "v4int8c"},
   {&slaw_is_v4int8c_array, "v4int8c_array"},
   {&slaw_is_v4unt8c, "v4unt8c"},
   {&slaw_is_v4unt8c_array, "v4unt8c_array"},
   {&slaw_is_v4int16c, "v4int16c"},
   {&slaw_is_v4int16c_array, "v4int16c_array"},
   {&slaw_is_v4unt16c, "v4unt16c"},
   {&slaw_is_v4unt16c_array, "v4unt16c_array"},
   {&slaw_is_m2int32, "m2int32"},
   {&slaw_is_m2int32_array, "m2int32_array"},
   {&slaw_is_m2unt32, "m2unt32"},
   {&slaw_is_m2unt32_array, "m2unt32_array"},
   {&slaw_is_m2int64, "m2int64"},
   {&slaw_is_m2int64_array, "m2int64_array"},
   {&slaw_is_m2unt64, "m2unt64"},
   {&slaw_is_m2unt64_array, "m2unt64_array"},
   {&slaw_is_m2float32, "m2float32"},
   {&slaw_is_m2float32_array, "m2float32_array"},
   {&slaw_is_m2float64, "m2float64"},
   {&slaw_is_m2float64_array, "m2float64_array"},
   {&slaw_is_m2int8, "m2int8"},
   {&slaw_is_m2int8_array, "m2int8_array"},
   {&slaw_is_m2unt8, "m2unt8"},
   {&slaw_is_m2unt8_array, "m2unt8_array"},
   {&slaw_is_m2int16, "m2int16"},
   {&slaw_is_m2int16_array, "m2int16_array"},
   {&slaw_is_m2unt16, "m2unt16"},
   {&slaw_is_m2unt16_array, "m2unt16_array"},
   {&slaw_is_m3int32, "m3int32"},
   {&slaw_is_m3int32_array, "m3int32_array"},
   {&slaw_is_m3unt32, "m3unt32"},
   {&slaw_is_m3unt32_array, "m3unt32_array"},
   {&slaw_is_m3int64, "m3int64"},
   {&slaw_is_m3int64_array, "m3int64_array"},
   {&slaw_is_m3unt64, "m3unt64"},
   {&slaw_is_m3unt64_array, "m3unt64_array"},
   {&slaw_is_m3float32, "m3float32"},
   {&slaw_is_m3float32_array, "m3float32_array"},
   {&slaw_is_m3float64, "m3float64"},
   {&slaw_is_m3float64_array, "m3float64_array"},
   {&slaw_is_m3int8, "m3int8"},
   {&slaw_is_m3int8_array, "m3int8_array"},
   {&slaw_is_m3unt8, "m3unt8"},
   {&slaw_is_m3unt8_array, "m3unt8_array"},
   {&slaw_is_m3int16, "m3int16"},
   {&slaw_is_m3int16_array, "m3int16_array"},
   {&slaw_is_m3unt16, "m3unt16"},
   {&slaw_is_m3unt16_array, "m3unt16_array"},
   {&slaw_is_m4int32, "m4int32"},
   {&slaw_is_m4int32_array, "m4int32_array"},
   {&slaw_is_m4unt32, "m4unt32"},
   {&slaw_is_m4unt32_array, "m4unt32_array"},
   {&slaw_is_m4int64, "m4int64"},
   {&slaw_is_m4int64_array, "m4int64_array"},
   {&slaw_is_m4unt64, "m4unt64"},
   {&slaw_is_m4unt64_array, "m4unt64_array"},
   {&slaw_is_m4float32, "m4float32"},
   {&slaw_is_m4float32_array, "m4float32_array"},
   {&slaw_is_m4float64, "m4float64"},
   {&slaw_is_m4float64_array, "m4float64_array"},
   {&slaw_is_m4int8, "m4int8"},
   {&slaw_is_m4int8_array, "m4int8_array"},
   {&slaw_is_m4unt8, "m4unt8"},
   {&slaw_is_m4unt8_array, "m4unt8_array"},
   {&slaw_is_m4int16, "m4int16"},
   {&slaw_is_m4int16_array, "m4int16_array"},
   {&slaw_is_m4unt16, "m4unt16"},
   {&slaw_is_m4unt16_array, "m4unt16_array"},
   {&slaw_is_m5int32, "m5int32"},
   {&slaw_is_m5int32_array, "m5int32_array"},
   {&slaw_is_m5unt32, "m5unt32"},
   {&slaw_is_m5unt32_array, "m5unt32_array"},
   {&slaw_is_m5int64, "m5int64"},
   {&slaw_is_m5int64_array, "m5int64_array"},
   {&slaw_is_m5unt64, "m5unt64"},
   {&slaw_is_m5unt64_array, "m5unt64_array"},
   {&slaw_is_m5float32, "m5float32"},
   {&slaw_is_m5float32_array, "m5float32_array"},
   {&slaw_is_m5float64, "m5float64"},
   {&slaw_is_m5float64_array, "m5float64_array"},
   {&slaw_is_m5int8, "m5int8"},
   {&slaw_is_m5int8_array, "m5int8_array"},
   {&slaw_is_m5unt8, "m5unt8"},
   {&slaw_is_m5unt8_array, "m5unt8_array"},
   {&slaw_is_m5int16, "m5int16"},
   {&slaw_is_m5int16_array, "m5int16_array"},
   {&slaw_is_m5unt16, "m5unt16"},
   {&slaw_is_m5unt16_array, "m5unt16_array"},
   {&slaw_is_nil, "nil"},
   {&slaw_is_string, "string"},
   {&slaw_is_cons, "cons"},
   {&slaw_is_list, "list"},
   {&slaw_is_map, "map"},
   {&slaw_is_list_or_map, "list_or_map"},
   {&slaw_is_protein, "protein"},
   {&slaw_is_swapped_protein, "swapped_protein"},
   {&slaw_is_boolean, "boolean"},
   {0, 0}};

void TestAgainstPredicates (ESlawType t, bslaw s)
{
  const SlawTypePredicateAndName *i = gSlawTypePredicateAndNames;
  const SlawTypePredicateAndName *const p = gSlawTypePredicateAndNames + t;
  for (; i->slawTypePredicate != 0; ++i)
    {
      const bool typeMatchExpected = i == p;
      if (typeMatchExpected != i->slawTypePredicate (s))
        {
          OB_FATAL_ERROR_CODE (0x20302000, "%s should%s be %s\n",
                               p->slawTypeName, typeMatchExpected ? "" : " not",
                               i->slawTypeName);
        }
    }
}