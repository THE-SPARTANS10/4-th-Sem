library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity testbench is
--empty
end testbench;

architecture tb of testbench is

component full_adder is
port(
  A: in std_logic;
  B: in std_logic;
  Cin: in std_logic;
  Sum: out std_logic;
  Cout: out std_logic);
end component;

signal a_in,b_in,c_in,sum_out,carry_out: std_logic;

begin
  DUT: full_adder port map(a_in,b_in,c_in,sum_out,carry_out);
  process
    begin
    a_in<='0';
    b_in<='0';
    c_in<='0';
    wait for 1 ns;
    
    a_in<='0';
    b_in<='0';
    c_in<='1';
    wait for 1 ns;
    
    a_in<='0';
    b_in<='1';
    c_in<='0';
    wait for 1 ns;
    
    a_in<='0';
    b_in<='1';
    c_in<='1';
    wait for 1 ns;
    
    a_in<='1';
    b_in<='0';
    c_in<='0';
    wait for 1 ns;
    
    a_in<='1';
    b_in<='0';
    c_in<='1';
    wait for 1 ns;
    
    a_in<='1';
    b_in<='1';
    c_in<='0';
    wait for 1 ns;
    
    a_in<='1';
    b_in<='1';
    c_in<='1';
    wait for 1 ns;
    wait;
end process;
end tb;