/*
  +----------------------------------------------------------------------+
  | Copyright (c) 2025 Pedro Padron <ppadron@php.net>                    |
  +----------------------------------------------------------------------+
  | Permission is hereby granted, free of charge, to any person          |
  | obtaining a copy of this software and associated documentation       |
  | files (the "Software"), to deal in the Software without              |
  | restriction, including without limitation the rights to use, copy,   |
  | modify, merge, publish, distribute, sublicense, and/or sell copies   |
  | of the Software, and to permit persons to whom the Software is       |
  | furnished to do so, subject to the following conditions:             |
  |                                                                      |
  | The above copyright notice and this permission notice shall be       |
  | included in all copies or substantial portions of the Software.      |
  |                                                                      |
  | THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,      |
  | EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF   |
  | MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND                |
  | NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  |
  | BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN   |
  | ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN    |
  | CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE     |
  | SOFTWARE.                                                            |
  +----------------------------------------------------------------------+
*/

#include "netinet/in.h"
#include "spf2/spf.h"

#ifndef PHP_SPF_H
#define PHP_SPF_H

extern zend_module_entry spf_module_entry;
#define phpext_spf_ptr &spf_module_entry

#ifdef PHP_WIN32
#	define PHP_SPF_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_SPF_API __attribute__ ((visibility("default")))
#else
#	define PHP_SPF_API
#endif

extern zend_class_entry* spf_ce_Spf;
extern zend_class_entry* spf_ce_SpfResponse;
extern zend_class_entry* spf_ce_SpfException;

typedef struct _spf_object {
	zend_object std;
	SPF_server_t *spf_server;
} php_spf_object;

typedef struct _spf_response_object {
	zend_object std;
	SPF_response_t *spf_response;
} php_spf_response_object;

zend_object *create_spf_response(zend_class_entry *class_type);
void free_spf_response(zend_object *object);

zend_object *create_spf(zend_class_entry *class_type);
void free_spf(zend_object *object);

PHP_MINIT_FUNCTION(spf);
PHP_MSHUTDOWN_FUNCTION(spf);
PHP_RINIT_FUNCTION(spf);
PHP_RSHUTDOWN_FUNCTION(spf);
PHP_MINFO_FUNCTION(spf);

PHP_METHOD(Spf, __construct);
PHP_METHOD(Spf, query);

PHP_METHOD(SpfResponse, getResult);
PHP_METHOD(SpfResponse, getHeaderComment);
PHP_METHOD(SpfResponse, getReceivedSpf);
PHP_METHOD(SpfResponse, getExplanation);
PHP_METHOD(SpfResponse, getSmtpComment);
PHP_METHOD(SpfResponse, getReceivedSpfValue);
PHP_METHOD(SpfResponse, hasErrors);
PHP_METHOD(SpfResponse, hasWarnings);
PHP_METHOD(SpfResponse, getErrors);
PHP_METHOD(SpfResponse, getWarnings);

#endif


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
