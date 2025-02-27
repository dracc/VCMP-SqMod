// ------------------------------------------------------------------------------------------------
#include "Base/Shared.hpp"
#include "Base/Buffer.hpp"
#include "Base/Color3.hpp"
#include "Library/Numeric/Random.hpp"
#include "Library/Numeric/LongInt.hpp"
#include "Library/String.hpp"

// ------------------------------------------------------------------------------------------------
#include <cerrno>
#include <cstdio>
#include <cstring>
#include <cstdarg>
#include <algorithm>

// ------------------------------------------------------------------------------------------------
#ifdef SQMOD_OS_WINDOWS
    #include <windows.h>
#endif // SQMOD_OS_WINDOWS

// ------------------------------------------------------------------------------------------------
namespace SqMod {

// ------------------------------------------------------------------------------------------------
static const Color3 SQ_Color_List[] =
{
    Color3(240, 248, 255),
    Color3(250, 235, 215),
    Color3(0, 255, 255),
    Color3(127, 255, 212),
    Color3(240, 255, 255),
    Color3(245, 245, 220),
    Color3(255, 228, 196),
    Color3(0, 0, 0),
    Color3(255, 235, 205),
    Color3(0, 0, 255),
    Color3(138, 43, 226),
    Color3(165, 42, 42),
    Color3(222, 184, 135),
    Color3(95, 158, 160),
    Color3(127, 255, 0),
    Color3(210, 105, 30),
    Color3(255, 127, 80),
    Color3(100, 149, 237),
    Color3(255, 248, 220),
    Color3(220, 20, 60),
    Color3(0, 255, 255),
    Color3(0, 0, 139),
    Color3(0, 139, 139),
    Color3(184, 134, 11),
    Color3(169, 169, 169),
    Color3(0, 100, 0),
    Color3(189, 183, 107),
    Color3(139, 0, 139),
    Color3(85, 107, 47),
    Color3(255, 140, 0),
    Color3(153, 50, 204),
    Color3(139, 0, 0),
    Color3(233, 150, 122),
    Color3(143, 188, 143),
    Color3(72, 61, 139),
    Color3(47, 79, 79),
    Color3(0, 206, 209),
    Color3(148, 0, 211),
    Color3(255, 20, 147),
    Color3(0, 191, 255),
    Color3(105, 105, 105),
    Color3(30, 144, 255),
    Color3(178, 34, 34),
    Color3(255, 250, 240),
    Color3(34, 139, 34),
    Color3(255, 0, 255),
    Color3(220, 220, 220),
    Color3(248, 248, 255),
    Color3(255, 215, 0),
    Color3(218, 165, 32),
    Color3(128, 128, 128),
    Color3(0, 128, 0),
    Color3(173, 255, 47),
    Color3(240, 255, 240),
    Color3(255, 105, 180),
    Color3(205, 92, 92),
    Color3(75, 0, 130),
    Color3(255, 255, 240),
    Color3(240, 230, 140),
    Color3(230, 230, 250),
    Color3(255, 240, 245),
    Color3(124, 252, 0),
    Color3(255, 250, 205),
    Color3(173, 216, 230),
    Color3(240, 128, 128),
    Color3(224, 255, 255),
    Color3(250, 250, 210),
    Color3(211, 211, 211),
    Color3(144, 238, 144),
    Color3(255, 182, 193),
    Color3(255, 160, 122),
    Color3(32, 178, 170),
    Color3(135, 206, 250),
    Color3(119, 136, 153),
    Color3(176, 196, 222),
    Color3(255, 255, 224),
    Color3(0, 255, 0),
    Color3(50, 205, 50),
    Color3(250, 240, 230),
    Color3(255, 0, 255),
    Color3(128, 0, 0),
    Color3(102, 205, 170),
    Color3(0, 0, 205),
    Color3(186, 85, 211),
    Color3(147, 112, 219),
    Color3(60, 179, 113),
    Color3(123, 104, 238),
    Color3(0, 250, 154),
    Color3(72, 209, 204),
    Color3(199, 21, 133),
    Color3(25, 25, 112),
    Color3(245, 255, 250),
    Color3(255, 228, 225),
    Color3(255, 228, 181),
    Color3(255, 222, 173),
    Color3(0, 0, 128),
    Color3(253, 245, 230),
    Color3(128, 128, 0),
    Color3(107, 142, 35),
    Color3(255, 165, 0),
    Color3(255, 69, 0),
    Color3(218, 112, 214),
    Color3(238, 232, 170),
    Color3(152, 251, 152),
    Color3(175, 238, 238),
    Color3(219, 112, 147),
    Color3(255, 239, 213),
    Color3(255, 218, 185),
    Color3(205, 133, 63),
    Color3(255, 192, 203),
    Color3(221, 160, 221),
    Color3(176, 224, 230),
    Color3(128, 0, 128),
    Color3(255, 0, 0),
    Color3(188, 143, 143),
    Color3(65, 105, 225),
    Color3(139, 69, 19),
    Color3(250, 128, 114),
    Color3(244, 164, 96),
    Color3(46, 139, 87),
    Color3(255, 245, 238),
    Color3(160, 82, 45),
    Color3(192, 192, 192),
    Color3(135, 206, 235),
    Color3(106, 90, 205),
    Color3(112, 128, 144),
    Color3(255, 250, 250),
    Color3(0, 255, 127),
    Color3(70, 130, 180),
    Color3(210, 180, 140),
    Color3(0, 128, 128),
    Color3(216, 191, 216),
    Color3(255, 99, 71),
    Color3(64, 224, 208),
    Color3(238, 130, 238),
    Color3(245, 222, 179),
    Color3(255, 255, 255),
    Color3(245, 245, 245),
    Color3(255, 255, 0),
    Color3(154, 205, 50)
};

// ------------------------------------------------------------------------------------------------
const SLongInt & GetSLongInt()
{
    static SLongInt l;
    l.SetNum(0);
    return l;
}

const SLongInt & GetSLongInt(Int64 n)
{
    static SLongInt l;
    l.SetNum(n);
    return l;
}

const SLongInt & GetSLongInt(CSStr s)
{
    static SLongInt l;
    l = s;
    return l;
}

const ULongInt & GetULongInt()
{
    static ULongInt l;
    l.SetNum(0);
    return l;
}

const ULongInt & GetULongInt(Uint64 n)
{
    static ULongInt l;
    l.SetNum(n);
    return l;
}

const ULongInt & GetULongInt(CSStr s)
{
    static ULongInt l;
    l = s;
    return l;
}

// ------------------------------------------------------------------------------------------------
bool NameFilterCheck(CSStr filter, CSStr name)
{
    // If only one of them is null then they don't match
    if ((!filter && name) || (filter && !name))
    {
        return false;
    }
    // If they're both null or the filter is empty then there's nothing to check for
    else if ((!filter && !name) || (*filter == '\0'))
    {
        return true;
    }

    SQChar ch = 0;
    // Start comparing the strings
    while (true)
    {
        // Grab the current character from filter
        ch = *(filter++);
        // See if the filter or name was completed
        if (ch == '\0' || *name == '\0')
        {
            break; // They matched so far
        }
        // Are we supposed to perform a wild-card search?
        else if (ch == '*')
        {
            // Grab the next character from filter
            ch = *(filter++);
            // Start comparing characters until the first match
            while (*name != '\0')
            {
                if (*(name++) == ch)
                {
                    break;
                }
            }
        }
        // See if the character matches doesn't have to match
        else if (ch != '?' && *name != ch)
        {
            return false; // The character had to match and failed
        }
        else
        {
            ++name;
        }
    }

    // At this point the name satisfied the filter
    return true;
}

// ------------------------------------------------------------------------------------------------
bool NameFilterCheckInsensitive(CSStr filter, CSStr name)
{
    // If only one of them is null then they don't match
    if ((!filter && name) || (filter && !name))
    {
        return false;
    }
    // If they're both null or the filter is empty then there's nothing to check for
    else if ((!filter && !name) || (*filter == '\0'))
    {
        return true;
    }

    SQChar ch = 0;
    // Start comparing the strings
    while (true)
    {
        // Grab the current character from filter
        ch = static_cast< SQChar >(std::tolower(*(filter++)));
        // See if the filter or name was completed
        if (ch == '\0' || *name == '\0')
        {
            break; // They matched so far
        }
        // Are we supposed to perform a wild-card search?
        else if (ch == '*')
        {
            // Grab the next character from filter
            ch = static_cast< SQChar >(std::tolower(*(filter++)));
            // Start comparing characters until the first match
            while (*name != '\0')
            {
                if (static_cast< SQChar >(std::tolower(*(name++))) == ch)
                {
                    break;
                }
            }
        }
        // See if the character matches doesn't have to match
        else if (ch != '?' && static_cast< SQChar >(std::tolower(*name)) != ch)
        {
            return false; // The character had to match and failed
        }
        else
        {
            ++name;
        }
    }

    // At this point the name satisfied the filter
    return true;
}

// ------------------------------------------------------------------------------------------------
const Color3 & GetRandomColor()
{
    return SQ_Color_List[GetRandomUint8(0, (sizeof(SQ_Color_List) / sizeof(Color3)) - 1)];
}

// ------------------------------------------------------------------------------------------------
Color3 GetColor(StackStrF & name)
{
    return name.mLen <= 0 ? Color3() : GetColorStr(name.mPtr);
}

// ------------------------------------------------------------------------------------------------
Color3 GetColorStr(CSStr name)
{
    // See if we actually have something to search for
    if(!name || *name == '\0')
    {
        return Color3::NIL; // Use default color
    }
    // Clone the string into an editable version
    CSStr str = StrJustAlphaNum(name);
    str = StrToLowercase(str);
    // See if we still have a valid name after the cleanup
    if(!str || *str == '\0')
    {
        return Color3::NIL; // Use default color
    }
    // Calculate the name length
    const Uint32 len = std::strlen(str);
    // Get the most significant characters used to identify a weapon
    SQChar a = str[0], b = 0, c = 0, d = str[len-1];
    // Look for deeper specifiers
    if(len >= 3)
    {
        c = str[2];
        b = str[1];
    }
    else if(len >= 2)
    {
        b = str[1];
    }
    // Search for a pattern in the name
    switch(a)
    {
        // [A]liceBlue
        // [A]ntiqueWhite
        // [A]qua
        // [A]quamarine
        // [A]zure
        case 'a':
            switch (b)
            {
                // [Al]iceBlue
                case 'l': return Color3(240, 248, 255);
                // [Aq]ua[m]arine
                case 'm': return Color3(127, 255, 212);
                // [An]tiqueWhite
                case 'n': return Color3(250, 235, 215);
                // [Aq]ua
                // [Aq]uamarine
                case 'q':
                    // [Aq]u[a]
                    if (d == 'a') return Color3(0, 255, 255);
                    // [Aq]ua[m]arin[e]
                    else if (d == 'e' || (len > 4 && str[4] == 'm')) return Color3(127, 255, 212);
                    // Default to blank
                    else return Color3::NIL;
                // [Az]ure
                case 'z': return Color3(240, 255, 255);
                // Default to blank
                default: return Color3::NIL;
            }
        // [B]eige
        // [B]isque
        // [B]lack
        // [B]lanchedAlmond
        // [B]lue
        // [B]lueViolet
        // [B]rown
        // [B]urlyWood
        case 'b':
            switch (b)
            {
                // [B]lanched[A]lmond
                case 'a': return Color3(255, 235, 205);
                // [Be]ige
                case 'e': return Color3(245, 245, 220);
                // [Bi]sque
                case 'i': return Color3(255, 228, 196);
                // [Bl]ack
                // [Bl]anchedAlmond
                // [Bl]ue
                // [Bl]ueViolet
                case 'l':
                    // [Bl]a[ck]
                    if (d == 'k' || d == 'c') return Color3(0, 0, 0);
                    // [Bl]anched[A]lmon[d]
                    else if (d == 'd' || (len > 8 && str[8] == 'a')) return Color3(255, 235, 205);
                    // [Bl]u[e]
                    else if (d == 'e') return Color3(0, 0, 255);
                    // [Bl]ue[V]iole[t]
                    else if (d == 't' || (len > 4 && str[4] == 'v')) return Color3(138, 43, 226);
                    // Default to blank
                    else return Color3::NIL;
                // [Br]own
                case 'r': return Color3(165, 42, 42);
                // [Bu]rlyWood
                case 'u': return Color3(222, 184, 135);
                // [B]lue[V]iolet
                case 'v': return Color3(138, 43, 226);
                // Default to blank
                default: return Color3::NIL;
            }
        // [C]adetBlue
        // [C]hartreuse
        // [C]hocolate
        // [C]oral
        // [C]ornflowerBlue
        // [C]ornsilk
        // [C]rimson
        // [C]yan
        case 'c':
            switch (b)
            {
                // [Ca]detBlue
                case 'a': return Color3(95, 158, 160);
                // [Ch]artreuse
                // [Ch]ocolate
                case 'h':
                    // [Ch]artreuse
                    if (c == 'a') return Color3(127, 255, 0);
                    // [Ch]ocolate
                    else if (c == 'o') return Color3(210, 105, 30);
                    // Default to blank
                    else return Color3::NIL;
                // [Co]ral
                // [Co]rnflowerBlue
                // [Co]rnsilk
                case 'o':
                    // [Co]ra[l]
                    if (d == 'l') return Color3(255, 127, 80);
                    // [Co]rnflower[B]lu[e]
                    else if (d == 'e' || (len > 10 && str[10] == 'b')) return Color3(100, 149, 237);
                    // [Co]rnsil[k]
                    else if (d == 'k') return Color3(255, 248, 220);
                    // Default to blank
                    else return Color3::NIL;
                // [Cr]imson
                case 'r': return Color3(220, 20, 60);
                // [Cy]an
                case 'y': return Color3(0, 255, 255);
                // Default to blank
                default: return Color3::NIL;
            }
        // [D]arkBlue
        // [D]arkCyan
        // [D]arkGoldenRod
        // [D]arkGray
        // [D]arkGreen
        // [D]arkKhaki
        // [D]arkMagenta
        // [D]arkOliveGreen
        // [D]arkOrange
        // [D]arkOrchid
        // [D]arkRed
        // [D]arkSalmon
        // [D]arkSeaGreen
        // [D]arkSlateBlue
        // [D]arkSlateGray
        // [D]arkTurquoise
        // [D]arkViolet
        // [D]eepPink
        // [D]eepSkyBlue
        // [D]imGray
        // [D]odgerBlue
        case 'd':
            // [Di]mGray
            if (b == 'i' || b == 'g') return Color3(105, 105, 105);
            // [Do]dgerBlue
            else if (b == 'o' || b == 'b') return Color3(30, 144, 255);
            // [De]ep[P]in[k]
            else if (b == 'e' && (d == 'k' || (len > 4 && str[4] == 'p'))) return Color3(255, 20, 147);
            // [De]ep[S]kyBlu[e]
            else if (b == 'e' && (d == 'e' || (len > 4 && str[4] == 's'))) return Color3(0, 191, 255);
            // [Da]rkBlue
            // [Da]rkCyan
            // [Da]rkGoldenRod
            // [Da]rkGray
            // [Da]rkGreen
            // [Da]rkKhaki
            // [Da]rkMagenta
            // [Da]rkOliveGreen
            // [Da]rkOrange
            // [Da]rkOrchid
            // [Da]rkRed
            // [Da]rkSalmon
            // [Da]rkSeaGreen
            // [Da]rkSlateBlue
            // [Da]rkSlateGray
            // [Da]rkTurquoise
            // [Da]rkViolet
            else if (b == 'a') {
                // [Da]rk[B]lue
                if (c == 'b' || (len > 4 && str[4] == 'b')) return Color3(0, 0, 139);
                // [Da]rk[C]yan
                else if (c == 'c' || (len > 4 && str[4] == 'c')) return Color3(0, 139, 139);
                // [Da]rk[Go]ldenRo[d]
                else if ((len > 4 && str[4] == 'g') && (d == 'd' || d == 'o')) return Color3(184, 134, 11);
                // [Da]rk[G]r[ay]
                else if ((len > 4 && str[4] == 'g') && (d == 'y' || d == 'a')) return Color3(169, 169, 169);
                // [Da]rk[G]r[een]
                else if ((len > 4 && str[4] == 'g') && (d == 'n' || d == 'e')) return Color3(0, 100, 0);
                // [Da]rk[K]hak[i]
                else if (d == 'i' || c == 'k' || (len > 4 && str[4] == 'k')) return Color3(189, 183, 107);
                // [Da]rk[M]agent[a]
                else if (d == 'a' || c == 'm' || (len > 4 && str[4] == 'm')) return Color3(139, 0, 139);
                // [Da]rk[O]liveGr[een]
                else if ((len > 4 && str[4] == 'o') && (d == 'n' || d == 'e')) return Color3(85, 107, 47);
                // [Da]rk[O]r[a]ng[e]
                else if ((len > 4 && str[4] == 'o') && (d == 'e' || d == 'a')) return Color3(255, 140, 0);
                // [Da]rk[O]r[c]hi[d]
                else if ((len > 4 && str[4] == 'o') && (d == 'd' || d == 'c')) return Color3(153, 50, 204);
                // [Da]rk[R]ed
                else if (len > 4 && str[4] == 'r') return Color3(139, 0, 0);
                // [Da]rk[Sa]lmon
                else if (len > 5 && str[4] == 's' && str[5] == 'a') return Color3(233, 150, 122);
                // [Da]rk[Se]aGreen
                else if (len > 5 && str[4] == 's' && str[5] == 'e') return Color3(143, 188, 143);
                // [Da]rk[S]lateBlu[e]
                else if ((len > 4 && str[4] == 's') && (d == 'e' || d == 'b')) return Color3(72, 61, 139);
                // [Da]rk[S]lateGra[y]
                else if ((len > 4 && str[4] == 's') && (d == 'y' || d == 'g')) return Color3(47, 79, 79);
                // [Da]rk[T]urquoise
                else if (c == 't' || (len > 4 && str[4] == 't')) return Color3(0, 206, 209);
                // [Da]rk[V]iolet
                else if (c == 'v' || (len > 4 && str[4] == 'v')) return Color3(148, 0, 211);
                // Default to blank
                else return Color3::NIL;
            // Default to blank
            } else return Color3::NIL;
        // [F]ireBrick
        // [F]loralWhite
        // [F]orestGreen
        // [F]uchsia
        case 'f':
            switch (b)
            {
                // [Fi]re[B]rick
                case 'i':
                case 'b': return Color3(178, 34, 34);
                // [Fl]oral[W]hite
                case 'l':
                case 'w': return Color3(255, 250, 240);
                // [Fo]rest[G]reen
                case 'o':
                case 'g': return Color3(34, 139, 34);
                // [Fu]chsia
                case 'u': return Color3(255, 0, 255);
                // Default to blank
                default: return Color3::NIL;
            }
        // [G]ainsboro
        // [G]hostWhite
        // [G]old
        // [G]oldenRod
        // [G]ray
        // [G]reen
        // [G]reenYellow
        case 'g':
            // [Ga]insboro
            if (b == 'a') return Color3(220, 220, 220);
            // [Gh]ost[W]hite
            else if (b == 'h' || b == 'w') return Color3(248, 248, 255);
            // [Go]ld[e]n[R]od
            else if (len > 4 && (str[4] == 'e' || str[4] == 'r')) return Color3(218, 165, 32);
            // [Go]l[d]
            else if (b == 'o' && d == 'd') return Color3(255, 215, 0);
            // [Gray]
            else if (b == 'r' && (d == 'y' || d == 'a')) return Color3(128, 128, 128);
            // [Gr]een
            else if (b == 'r' && d == 'n') return Color3(0, 128, 0);
            // [Gr]eenYellow
            else if (b == 'r' && (d == 'w' || (len > 5 && str[5] == 'y'))) return Color3(173, 255, 47);
            // Default to blank
            else return Color3::NIL;
        // [H]oneyDew
        // [H]otPink
        case 'h':
            // [H]o[n]ey[D]e[w]
            if (d == 'w' || c == 'n' || (len > 5 && str[5] == 'd')) return Color3(240, 255, 240);
            // [H]o[tP]in[k]
            else if (d == 'k' || c == 't' || (len > 3 && str[3] == 'p')) return Color3(255, 105, 180);
            // Default to blank
            else return Color3::NIL;
        // [I]ndianRed
        // [I]ndigo
        // [I]vory
        case 'i':
            // [In]dian[R]e[d]
            if (b == 'n' && (d == 'd' || d == 'r')) return Color3(205, 92, 92);
            // [In]di[go]
            else if (b == 'n' && (d == 'o' || d == 'g')) return Color3(75, 0, 130);
            // [I]vory
            else if (b == 'v') return Color3(255, 255, 240);
            // Default to blank
            else return Color3::NIL;
        // [K]haki
        case 'k': return Color3(240, 230, 140);
        // [L]avender
        // [L]avenderBlush
        // [L]awnGreen
        // [L]emonChiffon
        // [L]ightBlue
        // [L]ightCoral
        // [L]ightCyan
        // [L]ightGoldenRodYellow
        // [L]ightGray
        // [L]ightGreen
        // [L]ightPink
        // [L]ightSalmon
        // [L]ightSeaGreen
        // [L]ightSkyBlue
        // [L]ightSlateGray
        // [L]ightSteelBlue
        // [L]ightYellow
        // [L]ime
        // [L]imeGreen
        // [L]inen
        case 'l':
            // [La]vende[r]
            if (b == 'a' && d == 'r') return Color3(230, 230, 250);
            // [La]vender[B]lus[h]
            else if (b == 'a' && (d == 'h' || d == 'b')) return Color3(255, 240, 245);
            // [Law]n[G]ree[n]
            else if (b == 'g' || (b == 'a' && (c == 'w' || d == 'n'))) return Color3(124, 252, 0);
            // [Le]mon[C]hiffon
            else if (b == 'e' || b == 'c') return Color3(255, 250, 205);
            // [Li]me[G]reen
            else if (b == 'g' || (b == 'i' && (len > 4 && str[4] == 'g'))) return Color3(50, 205, 50);
            // [Lime]
            else if (b == 'i' && c == 'm' && d == 'e') return Color3(0, 255, 0);
            // [Lin]e[n]
            else if (b == 'i' && (c == 'n' || d == 'n')) return Color3(250, 240, 230);
            // [Li]ghtBlue
            // [Li]ghtCoral
            // [Li]ghtCyan
            // [Li]ghtGoldenRodYellow
            // [Li]ghtGray
            // [Li]ghtGreen
            // [Li]ghtPink
            // [Li]ghtSalmon
            // [Li]ghtSeaGreen
            // [Li]ghtSkyBlue
            // [Li]ghtSlateGray
            // [Li]ghtSteelBlue
            // [Li]ghtYellow
            else if (b == 'i') {
                // [Li]ght[B]lue
                if (len > 5 && str[5] == 'b') return Color3(173, 216, 230);
                // [Li]ght[Co]ra[l]
                else if ((len > 5 && str[5] == 'c') && (d == 'l' || d == 'o')) return Color3(240, 128, 128);
                // [Li]ght[Cy]a[n]
                else if ((len > 5 && str[5] == 'c') && (d == 'n' || d == 'y')) return Color3(224, 255, 255);
                // [Li]ght[Go]ldenRodYello[w]
                else if ((len > 5 && str[5] == 'g') && (d == 'w' || d == 'o')) return Color3(250, 250, 210);
                // [Li]ght[G]r[ay]
                else if ((len > 5 && str[5] == 'g') && (d == 'y' || d == 'a')) return Color3(211, 211, 211);
                // [Li]ght[G]r[een]
                else if ((len > 5 && str[5] == 'g') && (d == 'n' || d == 'e')) return Color3(144, 238, 144);
                // [Li]ght[P]ink
                else if (len > 5 && str[5] == 'p') return Color3(255, 182, 193);
                // [Li]ght[Sa]lmon
                else if (len > 6 && str[5] == 's' && str[5] == 'a') return Color3(255, 160, 122);
                // [Li]ght[Se]aGreen
                else if (len > 6 && str[5] == 's' && str[5] == 'e') return Color3(32, 178, 170);
                // [Li]ght[Sk]yBlue
                else if (len > 6 && str[5] == 's' && str[5] == 'k') return Color3(135, 206, 250);
                // [Li]ght[Sl]ateGray
                else if (len > 6 && str[5] == 's' && str[5] == 'l') return Color3(119, 136, 153);
                // [Li]ght[St]eelBlue
                else if (len > 6 && str[5] == 's' && str[5] == 't') return Color3(176, 196, 222);
                // [Li]ght[Y]ellow
                else if (len > 5 && str[5] == 'y') return Color3(255, 255, 224);
                // Default to blank
                else return Color3::NIL;
            // Default to blank
            } else return Color3::NIL;
        // [M]agenta
        // [M]aroon
        // [M]ediumAquaMarine
        // [M]ediumBlue
        // [M]ediumOrchid
        // [M]ediumPurple
        // [M]ediumSeaGreen
        // [M]ediumSlateBlue
        // [M]ediumSpringGreen
        // [M]ediumTurquoise
        // [M]ediumVioletRed
        // [M]idnightBlue
        // [M]intCream
        // [M]istyRose
        // [M]occasin
        case 'm':
            // [Ma]genta
            if (b == 'a' && (c == 'a' || d == 'a')) return Color3(255, 0, 255);
            // [Ma]roon
            else if (b == 'a' && (c == 'r' || d == 'n' || d == 'o')) return Color3(128, 0, 0);
            // [Me]diumAquaMarine
            // [Me]diumBlue
            // [Me]diumOrchid
            // [Me]diumPurple
            // [Me]diumSeaGreen
            // [Me]diumSlateBlue
            // [Me]diumSpringGreen
            // [Me]diumTurquoise
            // [Me]diumVioletRed
            else if (b == 'e') {
                // [Me]dium[A]quaMarine
                if (c == 'a' || (len > 6 && str[6] == 'a')) return Color3(102, 205, 170);
                // [Me]dium[B]lue
                else if (c == 'b' || (len > 6 && str[6] == 'b')) return Color3(0, 0, 205);
                // [Me]dium[O]rchid
                else if (c == 'o' || (len > 6 && str[6] == 'o')) return Color3(186, 85, 211);
                // [Me]dium[P]urple
                else if (c == 'p' || (len > 6 && str[6] == 'p')) return Color3(147, 112, 219);
                // [Me]dium[T]urquoise
                else if (c == 't' || (len > 6 && str[6] == 't')) return Color3(72, 209, 204);
                // [Me]dium[V]ioletRed
                else if (c == 'v' || (len > 6 && str[6] == 'v')) return Color3(199, 21, 133);
                // [Me]dium[Se]aGreen
                else if (len > 7 && str[6] == 's' && str[7] == 'e') return Color3(60, 179, 113);
                // [Me]dium[Sl]ateBlue
                else if (len > 7 && str[6] == 's' && str[7] == 'l') return Color3(123, 104, 238);
                // [Me]dium[Sp]ringGreen
                else if (len > 7 && str[6] == 's' && str[7] == 'p') return Color3(0, 250, 154);
                // Default to blank
                else return Color3::NIL;
            }
            // [Mi]dnightBlue
            else if (b == 'i' && c == 'd') return Color3(25, 25, 112);
            // [Mi]ntCream
            else if (b == 'i' && c == 'n') return Color3(245, 255, 250);
            // [Mi]styRose
            else if (b == 'i' && c == 's') return Color3(255, 228, 225);
            // [Mo]ccasin
            else if (b == 'o') return Color3(255, 228, 181);
            // Default to blank
            else return Color3::NIL;
        // [N]avajoWhite
        // [N]avy
        case 'n':
            // [Na]vajo[W]hite
            if (c == 'v' || c == 'w') return Color3(255, 222, 173);
            // [Na]v[y]
            else if (c == 'a' || d == 'y') return Color3(0, 0, 128);
            // Default to blank
            else return Color3::NIL;
        // [O]ldLace
        // [O]live
        // [O]liveDrab
        // [O]range
        // [O]rangeRed
        // [O]rchid
        case 'o':
            // [Old]Lace
            if (b == 'l' && c == 'd') return Color3(253, 245, 230);
            // [Ol]ive[D]ra[b]
            else if (b == 'l' && (d == 'b' || d == 'd')) return Color3(107, 142, 35);
            // [Ol]iv[e]
            else if (b == 'l' && d == 'e') return Color3(128, 128, 0);
            // [Or]ange[R]e[d]
            else if (b == 'r' && (d == 'd' || d == 'r')) return Color3(255, 69, 0);
            // [Or]ang[e]
            else if (b == 'r' && d == 'e') return Color3(255, 165, 0);
            // [Orc]hid
            else if (d == 'c') return Color3(218, 112, 214);
            // Default to blank
            else return Color3::NIL;
        // [P]aleGoldenRod
        // [P]aleGreen
        // [P]aleTurquoise
        // [P]aleVioletRed
        // [P]apayaWhip
        // [P]eachPuff
        // [P]eru
        // [P]ink
        // [P]lum
        // [P]owderBlue
        // [P]urple
        case 'p':
            // [Pu]rple
            if (b == 'u') return Color3(128, 0, 128);
            // [Po]wderBlue
            else if (b == 'o') return Color3(176, 224, 230);
            // [Pi]nk
            else if (b == 'i') return Color3(255, 192, 203);
            // [Pl]um
            else if (b == 'l') return Color3(221, 160, 221);
            // [Pea]chPuff
            else if (b == 'e' && c == 'a') return Color3(255, 218, 185);
            // [Per]u
            else if (b == 'e' && c == 'r') return Color3(205, 133, 63);
            // [Pa]payaWhip
            else if (b == 'a' && c == 'p') return Color3(255, 239, 213);
            // [Pa]le[Go]ldenRod
            else if (b == 'a' && (len > 5 && str[4] == 'g' && str[5] == 'o')) return Color3(238, 232, 170);
            // [Pa]le[Gr]een
            else if (b == 'a' && (len > 5 && str[4] == 'g' && str[5] == 'r')) return Color3(152, 251, 152);
            // [Pa]le[T]urquoise
            else if (b == 'a' && (len > 4 && str[4] == 't')) return Color3(175, 238, 238);
            // [Pa]le[V]ioletRed
            else if (b == 'a' && (len > 4 && str[4] == 'v')) return Color3(219, 112, 147);
            // Default to blank
            else return Color3::NIL;
        // [R]ed
        // [R]osyBrown
        // [R]oyalBlue
        case 'r':
            // [Re]d
            if (b == 'e') return Color3(255, 0, 0);
            // [Ros]yBrown
            else if (b == 'o' && c == 's') return Color3(188, 143, 143);
            // [Roy]alBlue
            else if (b == 'o' && c == 'y') return Color3(65, 105, 225);
            // Default to blank
            else return Color3::NIL;
        // [S]addleBrown
        // [S]almon
        // [S]andyBrown
        // [S]eaGreen
        // [S]eaShell
        // [S]ienna
        // [S]ilver
        // [S]kyBlue
        // [S]lateBlue
        // [S]lateGray
        // [S]now
        // [S]pringGreen
        // [S]teelBlue
        case 's':
            // [Sad]dleBrown
            if (b == 'a' && c == 'd') return Color3(139, 69, 19);
            // [Sal]mon
            else if (b == 'a' && c == 'l') return Color3(250, 128, 114);
            // [San]dyBrown
            else if (b == 'a' && c == 'n') return Color3(244, 164, 96);
            // [Se]a[G]reen
            else if (b == 'e' && d == 'g') return Color3(46, 139, 87);
            // [Se]a[S]hell
            else if (b == 'e' && d == 's') return Color3(255, 245, 238);
            // [Sie]nna
            else if (b == 'i' && c == 'e') return Color3(160, 82, 45);
            // [Sil]ver
            else if (b == 'i' && c == 'l') return Color3(192, 192, 192);
            // [Sk]yBlue
            else if (b == 'k') return Color3(135, 206, 235);
            // [Sl]ateBlue
            else if (b == 'l' && (d == 'e' || (len > 5 && str[5] == 'b'))) return Color3(106, 90, 205);
            // [Sl]ateGray
            else if (b == 'l' && (d == 'y' || (len > 5 && str[5] == 'g'))) return Color3(112, 128, 144);
            // [Sn]ow
            else if (b == 'n') return Color3(255, 250, 250);
            // [Sp]ringGreen
            else if (b == 'p') return Color3(0, 255, 127);
            // [St]eelBlue
            else if (b == 't') return Color3(70, 130, 180);
            // Default to blank
            else return Color3::NIL;
        // [T]an
        // [T]eal
        // [T]histle
        // [T]omato
        // [T]urquoise
        case 't':
            switch(b)
            {
                // [Ta]n
                case 'a': return Color3(210, 180, 140);
                // [Te]al
                case 'e': return Color3(0, 128, 128);
                // [Th]istle
                case 'h': return Color3(216, 191, 216);
                // [To]mato
                case 'o': return Color3(255, 99, 71);
                // [Tu]rquoise
                case 'u': return Color3(64, 224, 208);
                // Default to blank
                default: return Color3::NIL;
            }
        // [V]iolet
        case 'v': return Color3(238, 130, 238);
        // [W]heat
        // [W]hite
        // [W]hiteSmoke
        case 'w':
            // [Wh]eat
            if (b == 'h' && c == 'e') return Color3(245, 222, 179);
            // [Wh]ite[S]moke
            else if (b == 'h' && (len > 5 && str[5] == 's')) return Color3(245, 245, 245);
            // [Whi]te
            else if (b == 'h' && c == 'i') return Color3(255, 255, 255);
            // Default to blank
            else return Color3::NIL;
        // [Y]ellow
        // [Y]ellowGreen
        case 'y':
            // [Ye]llow[G]reen
            if (b == 'e' && (len > 6 && str[6] == 'g')) return Color3(154, 205, 50);
            // [Yel]low
            else if (b == 'e' && c == 'l') return Color3(255, 255, 0);
            // Default to blank
            else return Color3::NIL;
        // Default to blank
        default: return Color3::NIL;
    }
}

// ------------------------------------------------------------------------------------------------
void SqThrowLastF(CSStr msg, ...)
{
    // Acquire a moderately sized buffer
    Buffer b(128);
    // Prepare the arguments list
    va_list args;
    va_start (args, msg);
    // Attempt to run the specified format
    if (b.WriteF(0, msg, args) == 0)
    {
        b.At(0) = '\0'; // Make sure the string is null terminated
    }
    // Finalize the argument list
    va_end(args);
#ifdef SQMOD_OS_WINDOWS
    // Get the error message, if any.
    const DWORD error_num = ::GetLastError();
    // Was there an error recorded?
    if(error_num == 0)
    {
        // Invoker is responsible for making sure this doesn't happen!
        SqThrowF("%s [Unknown error]", b.Data());
    }
    // The resulted message buffer
    LPSTR msg_buff = nullptr;
    // Attempt to obtain the error message
    const std::size_t size = FormatMessageA(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
        nullptr, error_num, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        reinterpret_cast< LPSTR >(&msg_buff), 0, nullptr);
    // Copy the message buffer before freeing it
    std::string message(msg_buff, size);
    //Free the message buffer
    LocalFree(msg_buff);
    // Now it's safe to throw the error
    SqThrowF("%s [%s]", b.Data(), message.c_str());
#else
    SqThrowF("%s [%s]", b.Data(), std::strerror(errno));
#endif // SQMOD_OS_WINDOWS
}

// ------------------------------------------------------------------------------------------------
static SQInteger SqPackRGB(SQInteger r, SQInteger g, SQInteger b)
{
    return static_cast< Int32 >(SQMOD_PACK_RGB(
            ConvTo< Uint8 >::From(r),
            ConvTo< Uint8 >::From(g),
            ConvTo< Uint8 >::From(b)
        ));
}

// ------------------------------------------------------------------------------------------------
static SQInteger SqPackRGBA(SQInteger r, SQInteger g, SQInteger b, SQInteger a)
{
    return static_cast< Int32 >(SQMOD_PACK_RGBA(
            ConvTo< Uint8 >::From(r),
            ConvTo< Uint8 >::From(g),
            ConvTo< Uint8 >::From(b),
            ConvTo< Uint8 >::From(a)
        ));
}

// ------------------------------------------------------------------------------------------------
static SQInteger SqPackARGB(SQInteger r, SQInteger g, SQInteger b, SQInteger a)
{
    return static_cast< Int32 >(SQMOD_PACK_ARGB(
            ConvTo< Uint8 >::From(a),
            ConvTo< Uint8 >::From(r),
            ConvTo< Uint8 >::From(g),
            ConvTo< Uint8 >::From(b)
        ));
}

// ------------------------------------------------------------------------------------------------
static SQInteger SqNameFilterCheck(HSQUIRRELVM vm)
{
    const Int32 top = sq_gettop(vm);
    // Was the filter string specified?
    if (top <= 1)
    {
        return sq_throwerror(vm, "Missing filter string");
    }
    // Was the name string specified?
    else if (top <= 2)
    {
        return sq_throwerror(vm, "Missing name string");
    }
    // Attempt to generate the string value
    StackStrF filter(vm, 2);
    // Have we failed to retrieve the string?
    if (SQ_FAILED(filter.Proc(false)))
    {
        return filter.mRes; // Propagate the error!
    }
    // Attempt to generate the string value
    StackStrF name(vm, 3);
    // Have we failed to retrieve the string?
    if (SQ_FAILED(name.Proc(true)))
    {
        return name.mRes; // Propagate the error!
    }
    // Make the comparison and push the result on the stack
    sq_pushbool(vm, NameFilterCheck(filter.mPtr, name.mPtr));
    // Specify that we have a return value on the stack
    return 1;
}

// ------------------------------------------------------------------------------------------------
static SQInteger SqNameFilterCheckInsensitive(HSQUIRRELVM vm)
{
    const Int32 top = sq_gettop(vm);
    // Was the filter string specified?
    if (top <= 1)
    {
        return sq_throwerror(vm, "Missing filter string");
    }
    // Was the name string specified?
    else if (top <= 2)
    {
        return sq_throwerror(vm, "Missing name string");
    }
    // Attempt to generate the string value
    StackStrF filter(vm, 2);
    // Have we failed to retrieve the string?
    if (SQ_FAILED(filter.Proc(false)))
    {
        return filter.mRes; // Propagate the error!
    }
    // Attempt to generate the string value
    StackStrF name(vm, 3);
    // Have we failed to retrieve the string?
    if (SQ_FAILED(name.Proc(true)))
    {
        return name.mRes; // Propagate the error!
    }
    // Make the comparison and push the result on the stack
    sq_pushbool(vm, NameFilterCheckInsensitive(filter.mPtr, name.mPtr));
    // Specify that we have a return value on the stack
    return 1;
}

// ================================================================================================
void Register_Base(HSQUIRRELVM vm)
{
    RootTable(vm)
    .Func(_SC("EpsEq"), &EpsEq< SQFloat, SQFloat >)
    .Func(_SC("EpsLt"), &EpsLt< SQFloat, SQFloat >)
    .Func(_SC("EpsGt"), &EpsGt< SQFloat, SQFloat >)
    .Func(_SC("EpsLtEq"), &EpsLtEq< SQFloat, SQFloat >)
    .Func(_SC("EpsGtEq"), &EpsGtEq< SQFloat, SQFloat >)
    .Func(_SC("ClampI"), &Clamp< SQInteger, SQInteger, SQInteger >)
    .Func(_SC("ClampF"), &Clamp< SQFloat, SQFloat, SQFloat >)
    .Func(_SC("ClampMinI"), &ClampMin< SQInteger, SQInteger >)
    .Func(_SC("ClampMinF"), &ClampMin< SQFloat, SQFloat >)
    .Func(_SC("ClampMaxI"), &ClampMax< SQInteger, SQInteger >)
    .Func(_SC("ClampMaxF"), &ClampMax< SQFloat, SQFloat >)
    .Func(_SC("NextPow2"), &NextPow2)
    .Func(_SC("SToB"), &SToB)
    .Func(_SC("PackRGB"), &SqPackRGB)
    .Func(_SC("PackRGBA"), &SqPackRGBA)
    .Func(_SC("PackARGB"), &SqPackARGB)
    .SquirrelFunc(_SC("NameFilterCheck"), &SqNameFilterCheck)
    .SquirrelFunc(_SC("NameFilterCheckInsensitive"), &SqNameFilterCheckInsensitive);
}

} // Namespace:: SqMod
