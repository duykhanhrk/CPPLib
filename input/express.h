/* Express */
#define USHORT_STANDARD_EXPRESS UShortStandardExpress
#define UINT_STANDARD_EXPRESS UIntStandardExpress

#define ExpressPrototype(express_name) \
        void (*express_name)(char, void_tp, void_tp, void_tp, position_tp, position_tp, color_tp, color_tp)

#define ExpressInit(express_name) \
        void express_name(char c, void_tp obj, void_tp max, void_tp min, position_tp position_x, position_tp position_y, color_tp f_color, color_tp b_color)

#define ExpressCall(express_name) \
        express_name(c, &obj, &max, &min, position_x, position_y, f_color, b_color);

#define ExpressHandle(express_name) \
        ExpressCall(express_name);

ExpressInit(UShortStandardExpress) {
  printf("%hu", VoidTypeToUShort(obj));
}

ExpressInit(UIntStandardExpress) {
  printf("%u", VoidTypeToUInt(obj));
}