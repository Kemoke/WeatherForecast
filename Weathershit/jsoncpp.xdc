<?xml version="1.0"?><doc>
<members>
<member name="M:Json.codePointToUTF8(System.UInt32)" decl="false" source="c:\users\kemoke\source\workspaces\weatherforecast\weathershit\jsoncpp.cpp" line="102">
Converts a unicode code-point to UTF-8.
</member>
<member name="M:Json.isControlCharacter(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte)" decl="false" source="c:\users\kemoke\source\workspaces\weatherforecast\weathershit\jsoncpp.cpp" line="134">
Returns true if ch is a control character (in range [1,31]).
</member>
<member name="F:uintToStringBufferSize" decl="false" source="c:\users\kemoke\source\workspaces\weatherforecast\weathershit\jsoncpp.cpp" line="138">
Constant that specify the size of the buffer that must be passed to
uintToString.
</member>
<member name="M:Json.uintToString(System.UInt64,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte**!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="false" source="c:\users\kemoke\source\workspaces\weatherforecast\weathershit\jsoncpp.cpp" line="146">
Converts an unsigned integer to string.
	* @param value Unsigned interger to convert to string
	* @param current Input/Output string buffer.
	*        Must have at least uintToStringBufferSize chars free.

</member>
<member name="M:Json.fixNumericLocale(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte*,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte*)" decl="false" source="c:\users\kemoke\source\workspaces\weatherforecast\weathershit\jsoncpp.cpp" line="159">
Change ',' to '.' everywhere in buffer.
	*
	* We had a sophisticated way, but it did not work in WinCE.
	* @see https://github.com/open-source-parsers/jsoncpp/pull/9

</member>
<member name="M:Json.duplicateStringValue(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.UInt32)" decl="false" source="c:\users\kemoke\source\workspaces\weatherforecast\weathershit\jsoncpp.cpp" line="2512">
Duplicates the specified string value.
	* @param value Pointer to the string to duplicate. Must be zero-terminated if
	*              length is "unknown".
	* @param length Length of the value. if equals to unknown, then it will be
	*               computed using strlen(value).
	* @return Pointer on the duplicate instance of string.

</member>
<member name="M:Json.releaseStringValue(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte*)" decl="false" source="c:\users\kemoke\source\workspaces\weatherforecast\weathershit\jsoncpp.cpp" line="2573">
Free the string duplicated by duplicateStringValue()/duplicateAndPrefixStringValue().

</member>
<member name="M:Json.Value.size" decl="false" source="c:\users\kemoke\source\workspaces\weatherforecast\weathershit\jsoncpp.cpp" line="3289">
Number of values in array or object
</member>
<member name="T:Json.CommentStyle" decl="false" source="c:\users\kemoke\source\workspaces\weatherforecast\weathershit\jsoncpp.cpp" line="4831">
Scoped enums are not available until C++11.
</member>
<member name="T:Json.CommentStyle.Enum" decl="false" source="c:\users\kemoke\source\workspaces\weatherforecast\weathershit\jsoncpp.cpp" line="4833">
Decide whether to write comments.
</member>
</members>
</doc>