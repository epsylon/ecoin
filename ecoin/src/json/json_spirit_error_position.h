// ECOin - Copyright (c) - 2014/2026 - GPLv3 - epsylon@riseup.net (https://03c8.net)
#ifndef JSON_SPIRIT_ERROR_POSITION
#define JSON_SPIRIT_ERROR_POSITION

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#include <string>

namespace json_spirit
{
    struct Error_position
    {
        Error_position();
        Error_position( unsigned int line, unsigned int column, const std::string& reason );
        bool operator==( const Error_position& lhs ) const;
        unsigned int line_;
        unsigned int column_;
        std::string reason_;
    };

    inline Error_position::Error_position()
    :   line_( 0 )
    ,   column_( 0 )
    {
    }

    inline Error_position::Error_position( unsigned int line, unsigned int column, const std::string& reason )
    :   line_( line )
    ,   column_( column )
    ,   reason_( reason )
    {
    }

    inline bool Error_position::operator==( const Error_position& lhs ) const
    {
        if( this == &lhs ) return true;

        return ( reason_ == lhs.reason_ ) &&
               ( line_   == lhs.line_ ) &&
               ( column_ == lhs.column_ ); 
}
}

#endif
