library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity testbench is
--empty
end testbench;

architecture tb of testbench is

component decoder24 is
port(
  A: in std_logic;
  B: in std_logic;
  O0: out std_logic;
  O1: out std_logic;
  O2: out std_logic;
  O3: out std_logic;
  );
end component;

signal a_in,b_in,o0_out,o1_out,o2_out,o3_out: std_logic;

begin
  DUT: decoder24 port map(a_in,b_in,o0_out,o1_out,o2_out,o3_out);
  process
    begin
    
    a_in<='0';
    b_in<='0';
    wait for 1 ns;
      
    a_in<='0';
    b_in<='1';
    wait for 1 ns;
      
    a_in<='1';
    b_in<='0';
    wait for 1 ns;
      
    a_in<='1';
    b_in<='1';
    wait for 1 ns;
    wait;
end process;
end tb;