# CloudMyIp
*Know your router public IP address, from anywhere. Great for cheap routers or IP cameras.*

**CloudMyIp** is an IOT device that _reads_ the public IP address assigned to your router by your ISP (Internet Service Provider), and _publishes_ it on a web page anyone can read with a link. 
Great for accessing your home network or IP cameras from abroad, saving the money for a subscription to a dynamic dns service (or the time spent for similar "free" services requiring you to connect and read their ads once a month for continued service).

## How it works:
* an ESP8266 module reads the home network public IP address using the [ipify.org](http://ipify.org) API
* the module echoes back the public IP address to the cloud, publishing  "dweet" using the [dweet.io](http://dweet.io) APIs.
* a web application running on [freeboard.io](http://freeboard.io) reads the dweet, and presents the public IP address nicely  using any web browser. 

