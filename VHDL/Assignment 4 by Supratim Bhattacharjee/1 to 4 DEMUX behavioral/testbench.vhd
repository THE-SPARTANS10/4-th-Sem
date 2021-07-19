library IEEE;
use IEEE.std_logic_1164.all;

entity testbench is
--empty
end testbench;

architecture tb of testbench is
component demux41 is
port(
  input: in std_logic;
  select_line: in std_logic_vector(1 downto 0);
  output: out std_logic_vector(3 downto 0));
end component;

signal i : std_logic;
signal s : std_logic_vector(1 downto 0);
signal y : std_logic_vector(3 downto 0);

begin
  DUT: demux41 port map(i,s,y);
process
begin
  i<='1';
  
  s<="00";
  wait for 1 ns;
  
  s<="01";
  wait for 1 ns;
  
  s<="10";
  wait for 1 ns;
  
  s<="11";
  wait for 1 ns;
  wait;
  
  end process;
end tb;