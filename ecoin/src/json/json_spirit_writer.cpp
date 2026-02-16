// ECOin - Copyright (c) - 2014/2026 - GPLv3 - epsylon@riseup.net (https://03c8.net)
#include "json_spirit_writer.h"
#include "json_spirit_writer_template.h"

void json_spirit::write( const Value& value, std::ostream& os )
{
    write_stream( value, os, false );
}

void json_spirit::write_formatted( const Value& value, std::ostream& os )
{
    write_stream( value, os, true );
}

std::string json_spirit::write( const Value& value )
{
    return write_string( value, false );
}

std::string json_spirit::write_formatted( const Value& value )
{
    return write_string( value, true );
}

#ifndef BOOST_NO_STD_WSTRING

void json_spirit::write( const wValue& value, std::wostream& os )
{
    write_stream( value, os, false );
}

void json_spirit::write_formatted( const wValue& value, std::wostream& os )
{
    write_stream( value, os, true );
}

std::wstring json_spirit::write( const wValue&  value )
{
    return write_string( value, false );
}

std::wstring json_spirit::write_formatted( const wValue&  value )
{
    return write_string( value, true );
}

#endif

void json_spirit::write( const mValue& value, std::ostream& os )
{
    write_stream( value, os, false );
}

void json_spirit::write_formatted( const mValue& value, std::ostream& os )
{
    write_stream( value, os, true );
}

std::string json_spirit::write( const mValue& value )
{
    return write_string( value, false );
}

std::string json_spirit::write_formatted( const mValue& value )
{
    return write_string( value, true );
}

#ifndef BOOST_NO_STD_WSTRING

void json_spirit::write( const wmValue& value, std::wostream& os )
{
    write_stream( value, os, false );
}

void json_spirit::write_formatted( const wmValue& value, std::wostream& os )
{
    write_stream( value, os, true );
}

std::wstring json_spirit::write( const wmValue&  value )
{
    return write_string( value, false );
}

std::wstring json_spirit::write_formatted( const wmValue&  value )
{
    return write_string( value, true );
}

#endif
