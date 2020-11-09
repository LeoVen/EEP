using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;

namespace Color
{
    /// <summary>
    /// Represents a Color with Red, Green, Blue and Alpha channels (not premultiplied), packed into an integer. Also contains utilities to convert between color spaces.
    /// </summary>
    ///
    /// Since the colors are stored in ARGB, if you create a Color from other color spaces you might lose precision.
    /// This means that converting back and forth between color spaces does not guarantee you getting the original value.
    /// All percentage values are within [0.0, 1.0] and the smallest possible delta is 1 / 255. So an alpha of 0.001 and 0.002 are the same.
    /// Static constructors take tuples and constructors take each value separately.
    ///
    /// Currently supported color spaces conversion: RGB, HSL, CMYK.
    public struct Color : IEquatable<Color>, ICloneable
    {
        /// <summary>
        /// Represents ARGB as a densely packed integer.
        /// </summary>
        public uint Value { get; private set; }

        #region Ctors

        /// <summary>
        /// Creates a new Color from an integer value.
        /// </summary>
        public Color(uint value)
        {
            Value = value;
        }

        /// <summary>
        /// Creates a Color from a hexadecimal string, converting it to an integer and assigning to Value.
        /// </summary>
        /// <param name="hexa">A string as a hexadecimal number</param>
        public Color(string hexa)
        {
            Value = Convert.ToUInt32(hexa, 16);
        }

        /// <summary>
        /// Creates a Color from Red, Green and Blue channels with 100% Alpha, ranging from [0, 255].
        /// </summary>
        /// <param name="r">Red value</param>
        /// <param name="g">Green value</param>
        /// <param name="b">Blue value</param>
        public Color(uint r, uint g, uint b)
        {
            if (NotInRgbRange(r, g, b))
                throw new ArgumentOutOfRangeException("", $"R, G, B and A need to be within [0, 255]. Instead got r: {r}, g: {g}, b: {b}");

            Value = BuildValue(0xFF, r, g, b);
        }

        /// <summary>
        /// Creates a Color from Red, Green, Blue and Alpha channels, ranging from [0, 255].
        /// </summary>
        /// <param name="r">Red value</param>
        /// <param name="g">Green value</param>
        /// <param name="b">Blue value</param>
        /// <param name="a">Alpha value</param>
        public Color(uint r, uint g, uint b, uint a)
        {
            if (NotInRgbRange(r, g, b) || a > 255)
                throw new ArgumentOutOfRangeException("", $"R, G, B and A need to be within [0, 255]. Instead got r: {r}, g: {g}, b: {b}, a: {a}");

            Value = BuildValue(a, r, g, b);
        }

        /// <summary>
        /// Creates a Color from Red, Green, Blue and Alpha channels, with RGB ranging from [0, 255], and Alpha, from [0.0, 1.0].
        /// </summary>
        /// <param name="r">Red value</param>
        /// <param name="g">Green value</param>
        /// <param name="b">Blue value</param>
        /// <param name="a">Alpha value</param>
        public Color(uint r, uint g, uint b, double a)
        {
            if (NotInRgbRange(r, g, b) || NotInPctRange(a))
                throw new ArgumentOutOfRangeException("", $"R, G, B need to be within [0, 255] and A within [0.0, 1.0]. Instead got r: {r}, g: {g}, b: {b}, a: {a}");

            var a_ = (uint)Math.Round(a * 255.0, 0);

            Value = BuildValue(a_, r, g, b);
        }

        /// <summary>
        /// Creates a Color from Red, Green and Blue channels with 100% Alpha, ranging from [0.0, 1.0].
        /// </summary>
        /// <param name="r">Red value</param>
        /// <param name="g">Green value</param>
        /// <param name="b">Blue value</param>
        public Color(double r, double g, double b)
        {
            if (NotInRgbRange(r, g, b))
                throw new ArgumentOutOfRangeException("", $"R, G and B need to be within [0.0, 1.0]. Instead got {nameof(r)}: {r}, {nameof(g)}: {g}, {nameof(b)}: {b}");

            var (r_, g_, b_) = PctToRgb(r, g, b);

            Value = BuildValue(0xFF, r_, g_, b_);
        }

        /// <summary>
        /// Creates a Color from Red, Green, Blue and Alpha channels, ranging from [0.0, 1.0].
        /// </summary>
        /// <param name="r">Red value</param>
        /// <param name="g">Green value</param>
        /// <param name="a">Alpha value</param>
        public Color(double r, double g, double b, double a)
        {
            if (NotInRgbRange(r, g, b) || NotInPctRange(a))
                throw new ArgumentOutOfRangeException("", $"R, G, B and A need to be within [0.0, 1.0]. Instead got {nameof(r)}: {r}, {nameof(g)}: {g}, {nameof(b)}: {b}, {nameof(a)}: {a}");

            var (r_, g_, b_) = PctToRgb(r, g, b);
            var a_ = (uint)Math.Round(a * 255.0, 0);

            Value = BuildValue(a_, r_, g_, b_);
        }

        #endregion

        #region Checks

        private static bool NotInPctRange(double v)
        {
            return v < 0.0 || v > 1.0001;
        }

        private static bool NotInByteRange(uint v)
        {
            return v > 255;
        }

        private static bool NotInRgbRange(double r, double g, double b)
        {
            return NotInPctRange(r) || NotInPctRange(g) || NotInPctRange(b);
        }

        private static bool NotInRgbRange(uint r, uint g, uint b)
        {
            return NotInByteRange(r) || NotInByteRange(g) || NotInByteRange(b);
        }

        private static bool NotInHslRange(double h, double s, double v)
        {
            return h < 0.0 || h > 359.0001 ||  NotInPctRange(s) || NotInPctRange(v);
        }

        private static bool NotInCmykRange(double c, double m, double y, double k)
        {
            return NotInPctRange(c) || NotInPctRange(m) || NotInPctRange(y) || NotInPctRange(k);
        }

        #endregion

        #region Getters

        /// <summary>
        /// The value of Alpha within [0, 255]
        /// </summary>
        public uint A => Value >> 24;

        /// <summary>
        /// The value of Red within [0, 255]
        /// </summary>
        public uint R => (Value >> 16) & 0xFF;

        /// <summary>
        /// The value of Green within [0, 255]
        /// </summary>
        public uint G => (Value >> 8) & 0xFF;

        /// <summary>
        /// The value of Blue within [0, 255]
        /// </summary>
        public uint B => Value & 0xFF;

        /// <summary>
        /// Masks off the Alpha value, returning only RGB
        /// </summary>
        public uint RGB => Value & 0xFFFFFF;

        /// <summary>
        /// Returns value of Alpha within [0.0, 1.0]
        /// </summary>
        public double Alpha => A / 255.0;

        /// <summary>
        /// Returns value of Red within [0.0, 1.0]
        /// </summary>
        public double Red => R / 255.0;

        /// <summary>
        /// Returns value of Green within [0.0, 1.0]
        /// </summary>
        public double Green => G / 255.0;

        /// <summary>
        /// Returns value of Blue within [0.0, 1.0]
        /// </summary>
        public double Blue => B / 255.0;

        /// <summary>
        /// Returns value of Hue within [0.0, 359.0]
        /// </summary>
        public double Hue
        {
            get {
                var r = Red;
                var g = Green;
                var b = Blue;

                var max = Math.Max(Math.Max(r, g), b);
                var min = Math.Min(Math.Min(r, g), b);
                var c = max - min;

                if (c != 0)
                {
                    if (max == r)
                    {
                        var segment = (g - b) / c;
                        var shift = 0 / 60;
                        if (segment < 0)
                            shift = 360 / 60;
                        return (segment + shift) * 60;
                    }
                    else if (max == g)
                    {
                        var segment = (b - r) / c;
                        var shift = 120 / 60;
                        return (segment + shift) * 60;
                    }
                    else if (max == b)
                    {
                        var segment = (r - g) / c;
                        var shift = 240 / 60;
                        return (segment + shift) * 60;
                    }
                }

                return 0;
            }
        }

        /// <summary>
        /// Returns value of Saturation within [0.0, 1.0]
        /// </summary>
        public double Saturation
        {
            get
            {
                var r = Red;
                var g = Green;
                var b = Blue;

                var max = Math.Max(Math.Max(r, g), b);
                var min = Math.Min(Math.Min(r, g), b);

                var l = (max + min) / 2; // Lightness

                if (min != max)
                {
                    if (l < 0.5)
                        return (max - min) / (max + min);

                    return (max - min) / (2 - max - min);
                }

                return 0;
            }
        }

        /// <summary>
        /// Returns value of Lightness within [0.0, 1.0]
        /// </summary>
        public double Lightness
        {
            get
            {
                var r = Red;
                var g = Green;
                var b = Blue;

                var max = Math.Max(Math.Max(r, g), b);
                var min = Math.Min(Math.Min(r, g), b);

                return (max + min) / 2;
            }
        }

        /// <summary>
        /// Returns value of Cyan within [0.0, 1.0]
        /// </summary>
        public double Cyan
        {
            get
            {
                var k = Black;
                return k == 1.0 ? 0.0 : (1.0 - Red - k) / (1.0 - k);
            }
        }

        /// <summary>
        /// Returns value of Magenta within [0.0, 1.0]
        /// </summary>
        public double Magenta
        {
            get
            {
                var k = Black;
                return k == 1.0 ? 0.0 : (1.0 - Green - k) / (1.0 - k);
            }
        }

        /// <summary>
        /// Returns value of Yellow within [0.0, 1.0]
        /// </summary>
        public double Yellow
        {
            get
            {
                var k = Black;
                return k == 1.0 ? 0.0 : (1.0 - Blue - k) / (1.0 - k);
            }
        }

        /// <summary>
        /// Returns value of Black within [0.0, 1.0]
        /// </summary>
        public double Black => 1.0 - Math.Max(Math.Max(Red, Green), Blue);

        /// <summary>
        /// Returns the relative Luminance (how bright to the human eye the color is) according to ITU BT.601.
        /// </summary>
        public double Luminance => (0.299 * R + 0.587 * G + 0.114 * B) / 255.0;

        /// <summary>
        /// Multiply the Alpha channel by all other channels, returning a new color with 100% Alpha.
        /// </summary>
        public Color Compose()
        {
            return new Color(Red * Alpha, Green * Alpha, Blue * Alpha, 1.0);
        }

        /// <summary>
        /// Returns a copy of this color.
        /// </summary>
        public Color Copy()
        {
            return new Color(Value);
        }

        // Local cached Random class.
        private static readonly Random random = new Random();

        /// <summary>
        /// Creates a random color with 100% Alpha.
        /// </summary>
        public static Color Random()
        {
            return new Color((uint)(random.Next()) | 0xFF000000);
        }

        #endregion

        #region Value Tuples

        /// <summary>
        /// A tuple with RGB values as integers within [0, 255].
        /// </summary>
        public (uint, uint, uint) RGBValuesInt()
        {
            return (R, G, B);
        }

        /// <summary>
        /// A tuple with RGB values within [0.0, 1.0].
        /// </summary>
        public (double, double, double) RGBValues()
        {
            return (Red, Green, Blue);
        }

        /// <summary>
        /// A tuple with RGBA values within [0, 255].
        /// </summary>
        public (uint, uint, uint, uint) RGBAValuesInt()
        {
            return (R, G, B, A);
        }

        /// <summary>
        /// A tuple with RGBA values within [0.0, 1.0].
        /// </summary>
        public (double, double, double, double) RGBAValues()
        {
            return (Red, Green, Blue, Alpha);
        }

        /// <summary>
        /// A tuple with HSL values within [0.0, 1.0].
        /// </summary>
        public (double, double, double) HSLValues()
        {
            return RgbToHslInt((R, G, B));
        }

        /// <summary>
        /// A tuple with HSLA values within [0.0, 1.0].
        /// </summary>
        public (double, double, double, double) HSLAValues()
        {
            var (h, s, l) = RgbToHslInt((R, G, B));
            return (h, s, l, Alpha);
        }

        /// <summary>
        /// A tuple with CMYK values within [0.0, 1.0].
        /// </summary>
        public (double, double, double, double) CMYKValues()
        {
            return RgbToCmykInt((R, G, B));
        }

        /// <summary>
        /// A tuple with CMYK values within [0.0, 1.0].
        /// </summary>
        public (double, double, double, double, double) CMYKAValues()
        {
            var (c, m, y, k) = RgbToCmykInt((R, G, B));
            return (c, m, y, k, Alpha);
        }

        #endregion

        #region Builders

        /// <summary>
        /// Returns this with the specified Red component.
        /// </summary>
        /// <param name="red">Red value between [0, 255].</param>
        public Color WithRed(uint red)
        {
            if (red > 255)
                throw new ArgumentOutOfRangeException(nameof(red), $"Red need to be within [0, 255]. Instead got {nameof(red)}: {red}");

            Value = BuildValue(A, red, G, B);

            return this;
        }

        /// <summary>
        /// Returns this with the specified Red component.
        /// </summary>
        /// <param name="red">Red value between [0.0, 1.0].</param>
        public Color WithRed(double red)
        {
            if (NotInPctRange(red))
                throw new ArgumentOutOfRangeException(nameof(red), $"Red need to be within [0.0, 1.0]. Instead got {nameof(red)}: {red}");

            Value = BuildValue(A, (uint)Math.Round(red * 255.0, 0), G, B);

            return this;
        }

        /// <summary>
        /// Returns this with the specified Green component.
        /// </summary>
        /// <param name="green">Green value between [0, 255].</param>
        public Color WithGreen(uint green)
        {
            if (green > 255)
                throw new ArgumentOutOfRangeException(nameof(green), $"Green need to be within [0, 255]. Instead got {nameof(green)}: {green}");

            Value = BuildValue(A, R, green, B);

            return this;
        }

        /// <summary>
        /// Returns this with the specified Green component.
        /// </summary>
        /// <param name="green">Green value between [0.0, 1.0].</param>
        public Color WithGreen(double green)
        {
            if (NotInPctRange(green))
                throw new ArgumentOutOfRangeException(nameof(green), $"Green need to be within [0.0, 1.0]. Instead got {nameof(green)}: {green}");

            Value = BuildValue(A, R, (uint)Math.Round(green * 255.0, 0), B);

            return this;
        }

        /// <summary>
        /// Returns this with the specified Blue component.
        /// </summary>
        /// <param name="blue">Blue value between [0, 255].</param>
        public Color WithBlue(uint blue)
        {
            if (blue > 255)
                throw new ArgumentOutOfRangeException(nameof(blue), $"Blue need to be within [0, 255]. Instead got {nameof(blue)}: {blue}");

            Value = BuildValue(A, R, G, blue);

            return this;
        }

        /// <summary>
        /// Returns this with the specified Blue component.
        /// </summary>
        /// <param name="blue">Blue value between [0.0, 1.0].</param>
        public Color WithBlue(double blue)
        {
            if (NotInPctRange(blue))
                throw new ArgumentOutOfRangeException(nameof(blue), $"Blue need to be within [0.0, 1.0]. Instead got {nameof(blue)}: {blue}");

            Value = BuildValue(A, R, G, (uint)Math.Round(blue * 255.0, 0));

            return this;
        }

        /// <summary>
        /// Returns this with the specified Alpha component.
        /// </summary>
        /// <param name="a">Alpha value between [0, 255].</param>
        public Color WithAlpha(uint a)
        {
            if (a > 255)
                throw new ArgumentOutOfRangeException(nameof(a), $"A need to be within [0, 255]. Instead got {nameof(a)}: {a}");

            Value = BuildValue(a, R, G, B);

            return this;
        }

        /// <summary>
        /// Returns this with the specified Alpha component.
        /// </summary>
        /// <param name="a">Alpha value between [0.0, 1.0].</param>
        public Color WithAlpha(double a)
        {
            if (NotInPctRange(a))
                throw new ArgumentOutOfRangeException(nameof(a), $"A need to be within [0.0, 1.0]. Instead got {nameof(a)}: {a}");

            var a_ = (uint)Math.Round(a * 255.0, 0);

            Value = BuildValue(a_, R, G, B);

            return this;
        }

        #endregion

        #region Static Ctors

        /// <summary>
        /// Creates a Color from a string, converting it to an integer and assigning to Value.
        /// </summary>
        /// <param name="hexa">A string as a hexadecimal number</param>
        public static Color FromHexa(string hexa)
        {
            return new Color(hexa);
        }

        /// <summary>
        /// Creates a Color from Red, Green, Blue and Alpha channels. All numbers ranging from 0 to 255.
        /// </summary>
        /// <param name="rgb">A tuple of form (R, G, B)</param>
        /// <param name="a">Alpha value</param>
        public static Color FromRGBA((uint, uint, uint) rgb, uint a)
        {
            var (r, g, b) = rgb;
            return new Color(r, g, b, a);
        }

        /// <summary>
        /// Creates a Color from Red, Green, Blue and Alpha channels. RGB ranging from 0 to 255, and Alpha, from 0.0 to 1.0.
        /// </summary>
        /// <param name="rgb">A tuple of form (R, G, B)</param>
        /// <param name="a">Alpha value</param>
        public static Color FromRGBA((uint, uint, uint) rgb, double a)
        {
            var (r, g, b) = rgb;
            return new Color(r, g, b, a);
        }

        /// <summary>
        /// Creates a Color from Red, Green, Blue and Alpha components. All numbers ranging from 0.0 to 1.0.
        /// </summary>
        /// <param name="rgb">A tuple of form (R, G, B)</param>
        /// <param name="a">Alpha value</param>
        public static Color FromRGBA((double, double, double) rgb, double a)
        {
            var (r, g, b) = rgb;
            return new Color(r, g, b, a);
        }

        /// <summary>
        /// Creates a Color from Red, Green and Blue channels with 100% Alpha and values within [0, 255].
        /// </summary>
        /// <param name="rgb">A tuple of form (R, G, B)</param>
        public static Color FromRGB((uint, uint, uint) rgb)
        {
            return FromRGBA(rgb, 255);
        }

        /// <summary>
        /// Creates a Color from Red, Green and Blue channels with 100% Alpha and values within [0.0, 1.0].
        /// </summary>
        /// <param name="rgb">A tuple of form (R, G, B)</param>
        public static Color FromRGB((double, double, double) rgb)
        {
            return FromRGBA(rgb, 1.0);
        }

        /// <summary>
        /// Creates a Color from Hue, Saturation and Value, with Hue within [0.0, 359.0], and the others, within [0.0, 1.0]. Alpha is at 100%.
        /// </summary>
        /// <param name="hsl">A tuple of form (H, S, L)</param>
        public static Color FromHSL((double, double, double) hsl)
        {
            return FromRGBA(HslToRgb(hsl), 1.0);
        }

        /// <summary>
        /// Creates a Color from Hue, Saturation, Value, and Alpha, with Hue within [0.0, 359.0], and the others, within [0.0, 1.0].
        /// </summary>
        /// <param name="hsl">A tuple of form (H, S, L)</param>
        /// <param name="a">Alpha value</param>
        public static Color FromHSLA((double, double, double) hsl, double a)
        {
            return FromRGBA(HslToRgb(hsl), a);
        }

        /// <summary>
        /// Creates a Color from Cyan, Magenta, Yellow and Black, with values within [0.0, 1.0].
        /// </summary>
        /// <param name="hsl">A tuple of form (C, M, Y, K)</param>
        public static Color FromCMYK((double, double, double, double) cmyk)
        {
            return FromRGBA(CmykToRgb(cmyk), 1.0);
        }

        /// <summary>
        /// Creates a Color from Cyan, Magenta, Yellow, Black and Alpha, with values within [0.0, 1.0].
        /// </summary>
        /// <param name="hsl">A tuple of form (C, M, Y, K)</param>
        /// <param name="a">Alpha value</param>
        /// <returns></returns>
        public static Color FromCMYKA((double, double, double, double) cmyk, double a)
        {
            return FromRGBA(CmykToRgb(cmyk), a);
        }

        #endregion

        #region Conversions

        /// <summary>
        /// Transforms RGB color space to HSL.
        /// </summary>
        ///
        /// RGB values must be in range [0.0, 1.0].
        ///
        /// <param name="rgb">A tuple of form (Red, Green, Blue)</param>
        /// <returns>A tuple of form Tuple of form (Hue, Saturation, Lightness)</returns>
        public static (double, double, double) RgbToHsl((double, double, double) rgb)
        {
            double hue = 0.0, sat = 0.0, light;

            (double r, double g, double b) = rgb;

            if (NotInRgbRange(r, g, b))
                throw new ArgumentOutOfRangeException(nameof(rgb), $"R, G and B must be in range [0.0, 1.0]. Instead got r: {r}, g: {g}, b: {b}");

            var max = Math.Max(Math.Max(r, g), b);
            var min = Math.Min(Math.Min(r, g), b);

            var c = max - min;

            if (c != 0)
            {
                if (max == r)
                {
                    var segment = (g - b) / c;
                    var shift = 0 / 60;
                    if (segment < 0)
                        shift = 360 / 60;
                    hue = (segment + shift) * 60;
                }
                else if (max == g)
                {
                    var segment = (b - r) / c;
                    var shift = 120 / 60;
                    hue =  (segment + shift) * 60;
                }
                else if (max == b)
                {
                    var segment = (r - g) / c;
                    var shift = 240 / 60;
                    hue = (segment + shift) * 60;
                }
            }

            light = (max + min) / 2;

            if (min != max)
            {
                if (light < 0.5)
                    sat = (max - min) / (max + min);
                else
                    sat = (max - min) / (2 - max - min);
            }

            return (hue, sat, light);
        }

        /// <summary>
        /// Transforms RGB color space to HSL.
        /// </summary>
        ///
        /// RGB values must be in range [0, 255].
        ///
        /// <param name="rgb">A tuple of form (Red, Green, Blue)</param>
        /// <returns>A tuple of form (Hue, Saturation, Lightness) within [0.0, 1.0]</returns>
        public static (double, double, double) RgbToHslInt((uint, uint, uint) rgb)
        {
            (uint r_, uint g_, uint b_) = rgb;

            if (NotInRgbRange(r_, g_, b_))
                throw new ArgumentOutOfRangeException(nameof(rgb), $"R, G and B must be in range [0, 255]. Instead got r: {r_}, g: {g_}, b: {b_}");

            (double r, double g, double b) = RgbToPct(r_, g_, b_);

            return RgbToHsl((r, g, b));
        }

        /// <summary>
        /// Transforms RGB color space to CMYK.
        /// </summary>
        ///
        /// RGB values must be in range [0.0, 1.0].
        ///
        /// <param name="rgb">A tuple of form (Red, Green, Blue)</param>
        /// <returns>A tuple of form (Cyan, Magenta, Yellow, Black) within [0.0, 1.0]</returns>
        public static (double, double, double, double) RgbToCmyk((double, double, double) rgb)
        {
            double c, m, y, k;

            (double r, double g, double b) = rgb;

            if (NotInRgbRange(r, g, b))
                throw new ArgumentOutOfRangeException(nameof(rgb), $"R, G and B must be in range [0.0, 1.0]. Instead got r: {r}, g: {g}, b: {b}");

            var max = Math.Max(Math.Max(r, g), b);

            k = 1 - max;

            if (k == 1)
            {
                c = m = y = 0;
            }
            else
            {
                c = (1 - r - k) / (1 - k);
                m = (1 - g - k) / (1 - k);
                y = (1 - b - k) / (1 - k);
            }

            return (c, m, y, k);
        }

        /// <summary>
        /// Transforms RGB color space to CMYK.
        /// </summary>
        ///
        /// RGB values must be in range [0, 255].
        ///
        /// <param name="rgb">A tuple of form (Red, Green, Blue)</param>
        /// <returns>A tuple of form (Cyan, Magenta, Yellow, Black) within [0.0, 1.0]</returns>
        public static (double, double, double, double) RgbToCmykInt((uint, uint, uint) rgb)
        {
            (uint r_, uint g_, uint b_) = rgb;

            if (NotInRgbRange(r_, g_, b_))
                throw new ArgumentOutOfRangeException(nameof(rgb), $"R, G and B must be in range [0, 255]. Instead got r: {r_}, g: {g_}, b: {b_}");

            (double r, double g, double b) = RgbToPct(r_, g_, b_);

            return RgbToCmyk((r, g, b));
        }

        /// <summary>
        /// Transforms HSL color space to RGB.
        /// </summary>
        ///
        /// H value must be in range [0.0, 359.0] and SL values must be in range [0.0, 1.0].
        ///
        /// <param name="hsl">A tuple of form (Hue, Saturation, Lightness)</param>
        /// <returns>A tuple of form (Red, Green, Blue) within [0.0, 1.0]</returns>
        public static (double, double, double) HslToRgb((double, double, double) hsl)
        {
            (double hue, double sat, double light) = hsl;

            if (NotInHslRange(hue, sat, light))
                throw new ArgumentOutOfRangeException(nameof(hsl), $"H must be in range [0.0, 359.0], and S and L must be in range [0.0, 1.0]. Instead got h: {hue}, s: {sat}, l: {light}");

            hue /= 60;

            double t2;
            if (light <= 0.5)
            {
                t2 = light * (sat + 1);
            }
            else
            {
                t2 = light + sat - (light * sat);
            }

            double t1 = light * 2 - t2;

            return (HueToRgb(t1, t2, hue + 2.0), HueToRgb(t1, t2, hue), HueToRgb(t1, t2, hue - 2));
        }

        /// <summary>
        /// Transforms HSL color space to RGB.
        /// </summary>
        ///
        /// H value must be in range [0.0, 359.0] and SL values must be in range [0.0, 1.0].
        ///
        /// <param name="hsl">A tuple of form (Hue, Saturation, Lightness)</param>
        /// <returns>A tuple of form (Red, Green, Blue)</returns>
        public static (uint, uint, uint) HslToRgbInt((double, double, double) hsl)
        {
            var (r, g, b) = HslToRgb(hsl);
            return PctToRgb(r, g, b);
        }

        public static double HueToRgb(double t1, double t2, double hue)
        {
            if (hue < 0.0)
                hue += 6.0;
            if (hue >= 6.0)
                hue -= 6.0;

            if (hue < 1.0)
                return (t2 - t1) * hue + t1;
            else if (hue < 3.0)
                return t2;
            else if (hue < 4.0)
                return (t2 - t1) * (4.0 - hue) + t1;

            return t1;
        }

        /// <summary>
        /// Transforms CMYK color space to RGB.
        /// </summary>
        ///
        /// CMYK values must be in range [0.0, 1.0].
        ///
        /// <param name="cmyk">A tuple of form (Cyan, Magenta, Yellow, Black)</param>
        /// <returns>A tuple of form (Red, Green, Blue) within [0.0, 1.0]</returns>
        public static (double, double, double) CmykToRgb((double c, double m, double y, double k) cmyk)
        {
            var (c, m, y, k) = cmyk;

            if (NotInCmykRange(c, m, y, k))
                throw new ArgumentOutOfRangeException(nameof(cmyk), $"CMYK must be in range [0.0, 1.0]. Instead got c: {c}, m: {m}, y: {y}, k: {k}");

            var r = 1 - (Math.Min(1, c * (1 - k) + k));
            var g = 1 - (Math.Min(1, m * (1 - k) + k));
            var b = 1 - (Math.Min(1, y * (1 - k) + k));

            return (r, g, b);
        }

        /// <summary>
        /// Transforms CMYK color space to RGB.
        /// </summary>
        ///
        /// CMYK values must be in range [0.0, 1.0].
        ///
        /// <param name="cmyk">A tuple of form (Cyan, Magenta, Yellow, Black)</param>
        /// <returns>A tuple of form (Red, Green, Blue)</returns>
        public static (uint, uint, uint) CmykToRgbInt((double c, double m, double y, double k) cmyk)
        {
            var (r, g, b) = CmykToRgb(cmyk);
            return PctToRgb(r, g, b);
        }

        #endregion

        #region Variants

        /// <summary>
        /// Creates N variants of the current color by mixing the provided color with increasing weights.
        /// </summary>
        /// <param name="color">Color to be mixed</param>
        /// <param name="n">How many variants</param>
        public List<Color> Variants(Color color, int n)
        {
            var result = new List<Color>(n);

            for (int i = 0; i < n; i++)
                result.Add(Mix(color, (1.0 / n) * (i + 1)));

            return result;
        }

        /// <summary>
        /// Creates N tints of the current color. Tints are mixed with white, with increasing weights.
        /// </summary>
        /// <param name="n">How many tint variants</param>
        public List<Color> Tints(int n)
        {
            return Variants(new Color(0xFFFFFFFF), n);
        }

        /// <summary>
        /// Creates N shades of the current color. Shades are mixed with black, with increasing weights.
        /// </summary>
        /// <param name="n">How many shade variants</param>
        public List<Color> Shades(int n)
        {
            return Variants(new Color(0xFF000000), n);
        }

        /// <summary>
        /// Creates N colors from a color gradient from white to black with the current color in the middle.
        /// </summary>
        /// <param name="n">How many samples. This is always rounded up to an even number.</param>
        /// <returns>N + N % 2 colors with the same Hue, but different saturation and brightness.</returns>
        public List<Color> MonochromaticScheme(int n)
        {
            if (n <= 0)
                throw new ArgumentOutOfRangeException("n", "Must be greater than 0");

            n += n % 2;
            var steps = n / 2;

            var result = new List<Color>(n + 1);
            result.AddRange(Tints(steps).AsEnumerable().Reverse().ToList());
            result.Add(new Color(Value));
            result.AddRange(Shades(steps));

            return result;
        }

        /// <summary>
        /// Creates an Analogous Color scheme with two other colors with an offset.
        /// </summary>
        /// https://www.tigercolor.com/color-lab/color-theory/color-harmonies.htm
        /// <param name="hueOffset">Offset on the color wheel (Hue)</param>
        public List<Color> AnalogousScheme(double hueOffset = 30.0)
        {
            return new List<Color>()
            {
                FromHueOffset(-hueOffset),
                new Color(Value),
                FromHueOffset(hueOffset),
            };
        }

        /// <summary>
        /// Creates a Split Complementary color scheme.
        /// </summary>
        /// https://www.tigercolor.com/color-lab/color-theory/color-harmonies.htm
        public List<Color> SplitComplementaryScheme()
        {
            return new List<Color>()
            {
                FromHueOffset(-150.0),
                new Color(Value),
                FromHueOffset(150.0),
            };
        }

        /// <summary>
        /// Creates a Triadic color scheme.
        /// </summary>
        /// https://www.tigercolor.com/color-lab/color-theory/color-harmonies.htm
        public List<Color> TriadicScheme()
        {
            return new List<Color>()
            {
                FromHueOffset(-120.0),
                new Color(Value),
                FromHueOffset(120.0),
            };
        }

        /// <summary>
        /// Creates a Tetradic color scheme.
        /// </summary>
        /// https://www.tigercolor.com/color-lab/color-theory/color-harmonies.htm
        public List<Color> TetradicScheme()
        {
            return new List<Color>()
            {
                FromHueOffset(60.0),
                FromHueOffset(180.0),
                FromHueOffset(240.0),
                new Color(Value),
            };
        }

        /// <summary>
        /// Creates a square Tetradic color scheme.
        /// </summary>
        /// https://www.tigercolor.com/color-lab/color-theory/color-harmonies.htm
        public List<Color> TetradicSquareScheme()
        {
            return new List<Color>()
            {
                FromHueOffset(90.0),
                FromHueOffset(180.0),
                FromHueOffset(270.0),
                new Color(Value),
            };
        }

        /// <summary>
        /// Creates a new color from the Hue offset of the current one.
        /// </summary>
        /// <param name="hueOffset">Offset value in degrees.</param>
        public Color FromHueOffset(double hueOffset)
        {
            var (h, s, l) = RgbToHslInt((R, G, B));
            var hue = h + hueOffset;
            if (hue < 0.0)
                hue += 360.0;
            return FromHSLA((Math.Floor(hue % 360.0), s, l), Alpha);
        }

        /// <summary>
        /// Returns the complementary Color, that is, the one opposite on the color wheel.
        /// </summary>
        /// https://www.tigercolor.com/color-lab/color-theory/color-harmonies.htm
        public Color Complement()
        {
            return FromHueOffset(180);
        }

        #endregion

        #region Mixing

        /// <summary>
        /// Returns a new Color by mixing another one with 50 / 50 relevance, with default Alpha channel as 100%.
        /// </summary>
        /// <param name="c1"></param>
        public Color Mix(Color c1)
        {
            return Mix(c1, 0.5);
        }

        /// <summary>
        /// Returns a new Color by mixing another one with a given weight, with default Alpha channel as 100%.
        /// </summary>
        /// <param name="c1">Color to be mixed</param>
        /// <param name="w">Weight of color to be mixed</param>
        public Color Mix(Color c1, double w)
        {
            if (NotInPctRange(w))
                throw new ArgumentOutOfRangeException("w", $"Weight must be within [0.0, 1.0]. Instead got w: {w}");

            var c = 1.0 - w;

            var r = Red * c + c1.Red * w;
            var g = Green * c + c1.Green * w;
            var b = Blue * c + c1.Blue * w;

            return new Color(r, g, b, 1.0);
        }

        /// <summary>
        /// Mix two colors, a Source one on top of the Destination one, considering the latter with 100% Alpha.
        /// </summary>
        /// <param name="src">Source Color</param>
        /// <param name="dst">Destination Color</param>
        /// <returns></returns>
        public static Color MixAlpha(Color src, Color dst)
        {
            var r = src.Red * src.Alpha + dst.Red * (1 - src.Alpha);
            var g = src.Green * src.Alpha + dst.Green * (1 - src.Alpha);
            var b = src.Blue * src.Alpha + dst.Blue * (1 - src.Alpha);

            return new Color(r, g, b);
        }

        #endregion

        #region ToCSS

        /// <summary>
        /// Returns the Color to fit into an rgba CSS function, with form rbga(R, G, B, A).
        /// </summary>
        public string ToCssRgba()
        {
            return $"rgba({R}, {G}, {B}, {DefaultFormat(A / 255.0)})";
        }

        /// <summary>
        /// Returns the Color to fit into an hsla CSS function, with form hsl(H, S%, L%, A)
        /// </summary>
        public string ToCssHsla()
        {
            var (h, s, l) = RgbToHsl((Red, Green, Blue));
            return $"hsla({DefaultFormat(h)}, {DefaultFormat(s * 100)}%, {DefaultFormat(l * 100)}%, {DefaultFormat(A / 255.0)})";
        }

        /// <summary>
        /// Returns the Color with a format of #RRGGBB.
        /// </summary>
        public string ToCssColor()
        {
            return $"#{Convert.ToString(RGB, 16).PadLeft(6, '0')}";
        }

        #endregion

        #region Misc

        private static uint BuildValue(uint a, uint r, uint g, uint b)
        {
            return (((a & 0xFF) << 24) | ((r & 0xFF) << 16) | ((g & 0xFF) << 8) | ((b & 0xFF) << 0)) & 0xFFFFFFFF;
        }

        /// <summary>
        /// [0, 255] -> [0.0, 1.0]
        /// </summary>
        private static (double, double, double) RgbToPct(uint r, uint g, uint b)
        {
            return (r / 255.0, g / 255.0, b / 255.0);
        }

        /// <summary>
        /// [0.0, 1.0] -> [0, 255]
        /// </summary>
        private static (uint, uint, uint) PctToRgb(double r, double g, double b)
        {
            return ((uint)Math.Round(r * 255.0, 0), (uint)Math.Round(g * 255.0, 0), (uint)Math.Round(b * 255.0, 0));
        }

        private static string DefaultFormat(double value)
        {
            return value.ToString("0.##", CultureInfo.InvariantCulture);
        }

        #endregion

        #region Operators

        public static bool operator ==(Color lhs, Color rhs)
        {
            return lhs.Value == rhs.Value;
        }

        public static bool operator !=(Color lhs, Color rhs)
        {
            return lhs.Value != rhs.Value;
        }

        #endregion

        #region Overrides + Impls

        public override bool Equals(object obj)
        {
            if (obj is Color c)
                return Value == c.Value;

            return false;
        }

        public override int GetHashCode() => Value.GetHashCode();

        public override string ToString()
        {
            return Value.ToString("X");
        }

        public bool Equals(Color other)
        {
            return Value == other.Value;
        }

        public object Clone()
        {
            return new Color(Value);
        }

        #endregion
    }
}
