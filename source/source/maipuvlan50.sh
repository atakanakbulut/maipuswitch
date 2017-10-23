#!/bin/bash
enable
configure
vlan 1
exit
vlan 50
exit
interface vlan 50
ip address 50.23.20.22 255.255.255.0 gateway 0.0.0.0
exit
ip dhcp pool 1
network 50.23.20.20 255.255.255.0 50.23.20.25 50.23.20.30
lease 0 1 0
exit
ip dhcp-server
interface gigabitethernet 1
switchport mode trunk
switchport trunk allowed vlan add 50
exit
interface gigabitethernet 8
switchport mode trunk
switchport trunk allowed vlan add 50
exit
interface gigabitethernet 2
switchport mode access
switchport access vlan 50
exit
interface gigabitethernet 3
switchport mode access
switchport access vlan 50
exit
interface gigabitethernet 4
switchport mode access
switchport access vlan 50
exit
interface gigabitethernet 5
switchport mode access
switchport access vlan 50
exit
interface gigabitethernet 6
switchport mode access
switchport access vlan 50
exit
interface gigabitethernet 7
switchport mode access
switchport access vlan 50
exit
write
