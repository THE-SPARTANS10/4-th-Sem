library IEEE;
use IEEE.std_logic_1164.all;

entity testbench is
--empty
end testbench;

architecture tb of testbench is
component mux41 is
port(
  input: in std_logic_vector(3 downto 0);
  select_line: in std_logic_vector(1 downto 0);
  output: out std_logic);
end component;

signal i : std_logic_vector(3 downto 0);
signal s : std_logic_vector(1 downto 0);
signal y : std_logic;

begin
  DUT: mux41 port map(i,s,y);
process
begin
  i<="0001";
  s<="00";
  wait for 1 ns;
  
  i<="0010";
  s<="01";
  wait for 1 ns;
  
  i<="0100";
  s<="10";
  wait for 1 ns;
  
  i<="1000";
  s<="11";
  wait for 1 ns;
  wait;
  
  end process;
end tb;
