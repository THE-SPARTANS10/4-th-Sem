---------------------
library IEEE;
use IEEE.std_logic_1164.all;

entity Half_ad is
port(
	a,b: in std_logic;
	sum,car: out std_logic);
end Half_ad;
architecture part1 of Half_ad is
begin
   sum <= a xor b; car <= a and b;
end part1;
---------------------
library IEEE;
use IEEE.std_logic_1164.all;

entity Half_sub is
port(
	a,b: in std_logic;
	dif,bor: out std_logic);
end Half_sub;
architecture part2 of Half_sub is
begin
   dif <= a xor b; bor <= (not a) and b;
end part2;
---------------------
library IEEE;
use IEEE.std_logic_1164.all;

entity mux_4 is
port(
  a,b,c,d : in std_logic;
  s0,s1 : in std_logic;
  Y: out std_logic);
end mux_4;
architecture part3 of mux_4 is
begin
  process(a,b,c,d,s0,s1) is
    begin
   		if(s0='0' and s1='0') then Y<=a;
   		elsif(s0='0' and s1='1') then Y<=b;
   		elsif(s0='1' and s1='0') then Y<=c;
   		elsif(s0='1' and s1='1') then Y<=d;
   end if;
end process;
end part3;
---------------------  
library IEEE;
use IEEE.std_logic_1164.all;

entity ALU is
port(
  a,b : in std_logic;
  s0,s1 : in std_logic;
  Y0,Y1: out std_logic);
end ALU;
---------------------
architecture rtl of ALU is
  
component Half_ad is
	port(a,b: in std_logic; sum,car: out std_logic);
end component;

component Half_sub is
	port(a,b: in std_logic; dif,bor: out std_logic);
end component;   

component mux_4 is      
  port(a,b,c,d : in std_logic; s0,s1 : in std_logic;
  Y: out std_logic);
end component;

signal has,hac,hsd,hsb: std_logic;
begin
  HA1: Half_ad port map(a,b,has,hac);
  HS1: Half_sub port map(a,b,hsd,hsb);
  MUX1: mux_4 port map(has,hsd,a and b,'U',s0,s1,Y0);
  MUX2: mux_4 port map(hac,hsb,'U','U',s0,s1,Y1);
end rtl;