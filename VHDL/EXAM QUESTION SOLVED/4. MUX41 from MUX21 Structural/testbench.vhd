library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity testbench is
--empty
end testbench;

architecture tb of testbench is

component mux41 is
port(
  D0: in std_logic;
  D1: in std_logic;
  D2: in std_logic;
  D3: in std_logic;
  S1: in std_logic;
  S0: in std_logic;
  O: out std_logic;
  );
end component;

signal d0,d1,d2,d3,s1,s0,o: std_logic;

begin
  DUT: mux41 port map(d0,d1,d2,d3,s1,s0,o);
  process
    begin
    d0<='1';
    d1<='0';
    d2<='1';
    d3<='0';
    
    s1<='0';
    s0<='0';
    wait for 1 ns;
      
    s1<='0';
    s0<='1';
    wait for 1 ns;
      
    s1<='1';
    s0<='0';
    wait for 1 ns;
      
    s1<='1';
    s0<='1';
    wait for 1 ns;
    wait;
end process;
end tb;