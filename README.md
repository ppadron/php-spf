# PHP bindings for libspf2 (https://libspf2.net)

## Install

Make sure you install libspf2 development package first.

	$ git clone https://github.com/ppadron/php-spf
	$ cd php-spf
	$ phpize
	$ ./configure
	$ make
	$ sudo make install

Load the extension. (check your PHP configuration files path)

	$ echo "extension=spf.so" > /etc/php/conf.d/spf.ini

##  API

### Spf

	void        Spf::__construct([int $type[, string $domain[, string $spf]]])
	SpfResponse Spf::query(string $ip, string $helo, string $sender[, string $recipient])

#### Constants

- `Spf::TYPE_DNS_RESOLV` - Use DNS resolver for SPF lookups
- `Spf::TYPE_DNS_CACHE` - Use DNS cache for SPF lookups (default)
- `Spf::TYPE_DNS_ZONE` - Use DNS zone file for SPF lookups (requires domain and spf parameters)

### SpfResponse

	string  SpfResponse::getResult();
	string  SpfResponse::getHeaderComment();
	string  SpfResponse::getReceivedSpf();
	string  SpfResponse::getReceivedSpfValue();
	string  SpfResponse::getExplanation();
	string  SpfResponse::getSmtpComment();
	boolean SpfResponse::hasErrors();
	boolean SpfResponse::hasWarnings();
	array   SpfResponse::getErrors();
	array   SpfResponse::getWarnings();

#### Result Constants

- `SpfResponse::RESULT_INVALID` - Invalid result
- `SpfResponse::RESULT_NEUTRAL` - Neutral result (neither pass nor fail)
- `SpfResponse::RESULT_PASS` - SPF check passed
- `SpfResponse::RESULT_FAIL` - SPF check failed
- `SpfResponse::RESULT_SOFTFAIL` - SPF check soft-failed
- `SpfResponse::RESULT_NONE` - No SPF record found
- `SpfResponse::RESULT_TEMPERROR` - Temporary error occurred
- `SpfResponse::RESULT_PERMERROR` - Permanent error occurred

#### Error Constants

- `SpfResponse::ERROR_NO_MEMORY` - Out of memory error
- `SpfResponse::ERROR_NOT_SPF` - Record is not an SPF record
- `SpfResponse::ERROR_SYNTAX` - Syntax error in SPF record
- `SpfResponse::ERROR_MOD_W_PREF` - Invalid modifier 'w' preference
- `SpfResponse::ERROR_INVALID_CHAR` - Invalid character in SPF record
- `SpfResponse::ERROR_UNKNOWN_MECH` - Unknown mechanism
- `SpfResponse::ERROR_INVALID_OPT` - Invalid option
- `SpfResponse::ERROR_INVALID_CIDR` - Invalid CIDR notation
- `SpfResponse::ERROR_MISSING_OPT` - Missing required option
- `SpfResponse::ERROR_INTERNAL_ERROR` - Internal error
- `SpfResponse::ERROR_INVALID_ESC` - Invalid escape sequence
- `SpfResponse::ERROR_INVALID_VAR` - Invalid variable
- `SpfResponse::ERROR_BIG_SUBDOM` - Subdomain too large
- `SpfResponse::ERROR_INVALID_DELIM` - Invalid delimiter
- `SpfResponse::ERROR_BIG_STRING` - String too large
- `SpfResponse::ERROR_BIG_MECH` - Mechanism too large
- `SpfResponse::ERROR_BIG_MOD` - Modifier too large
- `SpfResponse::ERROR_BIG_DNS` - DNS record too large
- `SpfResponse::ERROR_INVALID_IP4` - Invalid IPv4 address
- `SpfResponse::ERROR_INVALID_IP6` - Invalid IPv6 address
- `SpfResponse::ERROR_INVALID_PREFIX` - Invalid prefix length
- `SpfResponse::ERROR_RESULT_UNKNOWN` - Unknown result
- `SpfResponse::ERROR_UNINIT_VAR` - Uninitialized variable
- `SpfResponse::ERROR_MOD_NOT_FOUND` - Modifier not found
- `SpfResponse::ERROR_NOT_CONFIG` - Not configured
- `SpfResponse::ERROR_DNS_ERROR` - DNS lookup error
- `SpfResponse::ERROR_BAD_HOST_IP` - Bad host IP address
- `SpfResponse::ERROR_BAD_HOST_TLD` - Bad host TLD
- `SpfResponse::ERROR_MECH_AFTER_ALL` - Mechanism found after 'all'
- `SpfResponse::ERROR_INCLUDE_RETURNED_NONE` - Include returned 'none'
- `SpfResponse::ERROR_RECURSIVE` - Recursive include detected
- `SpfResponse::ERROR_MULTIPLE_RECORDS` - Multiple SPF records found
