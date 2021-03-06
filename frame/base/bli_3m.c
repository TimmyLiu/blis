/*

   BLIS    
   An object-based framework for developing high-performance BLAS-like
   libraries.

   Copyright (C) 2014, The University of Texas at Austin

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    - Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    - Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    - Neither the name of The University of Texas at Austin nor the names
      of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
   HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#include "blis.h"

static char*  bli_3m_str        = "3m";

static bool_t bli_will_use_3m_c = FALSE;
static bool_t bli_will_use_3m_z = FALSE;


char*  bli_3m_get_string( void ) { return bli_3m_str; }

bool_t bli_3m_is_enabled_dt( num_t dt )
{
	if      ( bli_is_scomplex( dt ) ) return bli_3m_is_enabled_c();
	else if ( bli_is_dcomplex( dt ) ) return bli_3m_is_enabled_z();
	else                              return FALSE;
}
bool_t bli_3m_is_enabled_c( void ) { return bli_will_use_3m_c; }
bool_t bli_3m_is_enabled_z( void ) { return bli_will_use_3m_z; }


void bli_3m_enable_dt( num_t dt )
{
	if      ( bli_is_scomplex( dt ) ) bli_3m_enable_c();
	else if ( bli_is_dcomplex( dt ) ) bli_3m_enable_z();
}
void bli_3m_enable_c( void )  { bli_will_use_3m_c = TRUE; }
void bli_3m_enable_z( void )  { bli_will_use_3m_z = TRUE; }
void bli_3m_enable( void )    { bli_will_use_3m_c =
                                bli_will_use_3m_z = TRUE; }


void bli_3m_disable_dt( num_t dt )
{
	if      ( bli_is_scomplex( dt ) ) bli_3m_disable_c();
	else if ( bli_is_dcomplex( dt ) ) bli_3m_disable_z();
}

void bli_3m_disable_c( void )  { bli_will_use_3m_c = FALSE; }
void bli_3m_disable_z( void )  { bli_will_use_3m_z = FALSE; }
void bli_3m_disable( void )    { bli_will_use_3m_c =
                                 bli_will_use_3m_z = FALSE; }
