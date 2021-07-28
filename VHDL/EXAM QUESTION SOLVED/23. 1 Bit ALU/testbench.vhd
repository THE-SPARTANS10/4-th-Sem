library IEEE;
use IEEE.std_logic_1164.all;

entity testbench is
end testbench;

architecture A1 of testbench is
component ALU is
port(
  a,b : in std_logic;
  s0,s1 : in std_logic;
  Y0,Y1: out std_logic);
end component;

signal a_in,b_in: std_logic;
signal s0_in,s1_in: std_logic;
signal Y0_out,Y1_out: std_logic;

begin
DUT:ALU port map(a_in,b_in,s0_in,s1_in,Y0_out,Y1_out);

process
begin
a_in<='1';b_in<='1';

s0_in<='0';s1_in<='0';wait for 1 ns; 
s0_in<='0';s1_in<='1';wait for 1 ns;
s0_in<='1';s1_in<='0';wait for 1 ns;
s0_in<='1';s1_in<='1';wait for 1 ns;

wait;
end process;
end A1;