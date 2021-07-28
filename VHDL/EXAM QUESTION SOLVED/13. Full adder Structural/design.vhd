---------------------
library IEEE;
use IEEE.std_logic_1164.all;

entity Half_ad is
port(
	x,y: in std_logic;
	s1,c1: out std_logic);
end Half_ad;
---------------------
library IEEE;
use IEEE.std_logic_1164.all;

entity or_gate is
	port(
    x,y : in std_logic;
      Z : out std_logic);
end or_gate;
---------------------
library IEEE;
use IEEE.std_logic_1164.all;

entity Full_ad is
port(
  a,b,c_in: in std_logic;
  s,c: out std_logic);
end Full_ad;
---------------------
architecture part1 of or_gate is
begin
  Z <= x or y;
end part1;

architecture part2 of Half_ad is
begin
   s1 <= x xor y;
   c1 <= x and y;
end part2;
  
architecture rtl of Full_ad is
  
component Half_ad is
	port(x,y : in std_logic;
       s1,c1: out std_logic);
end Half_ad;

component or_gate is
	port(x,y : in std_logic;
           Z : out std_logic);
end or_gate;
signal s2,c2,c3: std_logic;
begin
  HA1: Half_ad port map(a,b,s2,c2);
  HA2: Half_ad port map(s2,c_in,s,c3);
  OR1: or_gate port map(c2,c3,c);
end rtl;