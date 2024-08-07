#include <pgmspace.h>
#define SECRET
#define THINGNAME "CapacitiveSensor"
const char WIFI_SSID[] = "wificreds";
const char WIFI_PASSWORD[] = "wificreds";
const char AWS_IOT_ENDPOINT[] = "a2n7icz5g08zo7-ats.iot.eu-north-1.amazonaws.com";
static const char AWS_CERT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy
rqXRfboQnoZsG4q5WTP468SQvvG5
-----END CERTIFICATE-----
)EOF";
static const char AWS_CERT_CRT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWjCCAkKgAwIBAgIVAJ96HI0cAuXhLSerNrMJWnchVAinMA0GCSqGSIb3DQEB
CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t
IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0yNDAxMjIxNDUz
MzdaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh
dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQC9KdITkPeFOmiDi3EO
RyqHSE2eeFNzihv4Gztmsq/vuxNHlOX2YlbBKEydq3bKDq9RT7V5yZ/y+sqsy7MQ
FbhV/hvofRXxRK99U8vgUDkEvAUzknbFHrsZ/0IZjt7A6AwP5PiQE2/RSbnwWWqC
D841Cf4vZVEK21Ztv9yLEGXGM7zFc+hAciM86oCDnOu8YGA6FeoePrLnfJiFxaxr
+ZLbdQyJx6b+zOrF3bRmMXfPWzc94Zm272h+56idPRDU/rMm7sAk+jesmrn7IM6r
PgdoqmuiQ0oVuWvX54UY0qomOLwvnF3A4QB4VER8fQYKK+7JeJx8sQQ3a3dl/QsV
E9npAgMBAAGjYDBeMB8GA1UdIwQYMBaAFKNOBvFwRGZJLqlEE2t5AgdHOgEhMB0G
A1UdDgQWBBTtEafOR0xtJzZGaUq6qQp7GpDPizAMBgNVHRMBAf8EAjAAMA4GA1Ud
DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEAI+HfPD+nAw36JPmkQuuy7YwP
6zzxJt3e4xqu7bBo+7NKkgNXiGBPHTG4zWYvgDGjpcIpB7czfwghCXayhgpTCWPj
rrdOItjDNJcOWO8HmMzT/goRLpV4g1xgULQVKlES54J7Ldv7W/e5JcX4L+Qaa7Kv
C76hKEGk2Luqs8bnEblkQfTVJbenJoAiEKAmgI5K2KyeC9I5UEClKSUM+QJwyanj
BXA3cIfvThafywLLkT7hwm9a7r8OHacCDc3/dFjLIZSXrftwo/cpUwIV4xVQZjO/
AAVadmA1ErjzejHESqUVMnI6f4RxvxnxIccOQU9xWRUtKmNy/oomiB6OftYE1w==
-----END CERTIFICATE-----

)KEY";
static const char AWS_CERT_PRIVATE[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEowIBAAKCAQEAvSnSE5D3hTpog4txDkcqh0hNnnhTc4ob+Bs7ZrKv77sTR5Tl
9mJWwShMnat2yg6vUU+1ecmf8vrKrMuzEBW4Vf4b6H0V8USvfVPL4FA5BLwFM5J2
xR67Gf9CGY7ewOgMD+T4kBNv0Um58Flqgg/ONQn+L2VRCttWbb/cixBlxjO8xXPo
QHIjPOqAg5zrvGBgOhXqHj6y53yYhcWsa/mS23UMicem/szqxd20ZjF3z1s3PeGZ
tu9ofueonT0Q1P6zJu7AJPo3rJq5+yDOqz4HaKprokNKFblr1+eFGNKqJji8L5xd
wOEAeFREfH0GCivuyXicfLEEN2t3Zf0LFRPZ6QIDAQABAoIBAClK0cLXqFB62Ymt
jLZTLqNtUxQ+q+jSwxw7xZG7e9BXA/RiOni4Krvrch4Q6dNdtUOIpNK7AqFlwYxK
wwHF3AFZgPoVJA8QsUYoXp7OpEO2T2RcmnSZKrqYD/PITjPJ86gckW3R8Fy9PUuM
GUXe8WJ+le/+q9w02P8IHLp2j+Dd1j3Re9F/klvOm0oKrDi3hs/16RRiGRqdUHmw
aAM7M1aYyIILj+uHUcALHputyExZ8q0Rg6LAwOppa/VT5xbxY3GXaZam51YAoCBk
JlN1y/DpQR5E91yulABrmuZT+BDMGSmWgKXTk5x3YCfEYKKvbAJflAsx1is4xKlU
9enPsykCgYEA4yoPRWGXyjzuxdGgPvEf1F331ZUfE+6haA95aKe320ycAqlzAFX0
WdySaxa7uDRUOyZwhCHqjtei6uun/ZogGDeOwvoHGkJLWCeZV+AV2kBDxWV4hqDG
BPh6ucmkwFA7RuZQxLyy7yZGtSQVtlDSDEcJzYSUER8TRaJUpO6zubcCgYEA1Szh
jAT6tCFbe0Pmcferx3U/GFL0EyGKgEEHIBdfjhT7xSVwNZT/H7i2bXFz40j1UoEW
hmus7BBgE8n+N1ylXxP40srPpeYkLqpUs7/hkzdEk9mwty/8cbwbrBoyISb6YYlK
14i9Mtqtq2tcvxS4SMNKS8m7gc2r6EmNSMn5iV8CgYAtRMBuTxh0kNf0S+XnJR32
sBMnWOQskK1Rk2PaWzHkXcvpK+Ni+b4L+kyjUpBuEN+IOgzKCAg6Fva8YeHEQ+aJ
bOjiKfkoXnWtR5bjUCCKsavPtnziNz++1dV/GJPgTxzA8DzAN+pghfwpNNuuzURO
dgmaDwWCs/KfOc4sX/Uo2QKBgBd39HDEz5DrJzYf2Ivtd1TjHIoh/8rnY2cRQaaP
zC5JMxqWL49Gkvu8CyFrXxXDn3ZwzbkIu6XVe65SC5GuumoIOdmDCG88MfmNOPv9
AOmDKSKZ0bGpL8KZsfY1gBVURDZetgWagTHLD1mS3UgQEOW50kEbuW/l46oUBuDf
k4BDAoGBAI4vK2bB+fZgG1fUh0PvXbsmGAyyRm+BndZH2G7952yt3CMQSMt1/+7Z
NSiZU7o3WWsF2f6RhOS08H18VS+ZhBInK0mOM2QnYyAG77tjIy39vjKEr8L4Cpbe
Upjgqk/HZi1V0ZE7Kbyxol82UBYc8VurHXzE6Qo21sb/PS/T4uCu
-----END RSA PRIVATE KEY-----
)KEY";
