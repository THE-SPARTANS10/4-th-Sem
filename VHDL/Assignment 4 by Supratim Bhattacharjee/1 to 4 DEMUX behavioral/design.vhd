library ieee;
use ieee.std_logic_1164.all;

entity demux41 is
port(
  input: in std_logic;
  select_line: in std_logic_vector(1 downto 0);
  output: out std_logic_vector(3 downto 0));
end demux41;

architecture behavioral of demux41 is
begin
  process(select_line)
  begin
    case select_line is
      when "00" =>
        output(3)<='0';
        output(2)<='0';
        output(1)<='0';
        output(0)<=input;
      when "01" =>
        output(3)<='0';
        output(2)<='0';
        output(1)<=input;
        output(0)<='0';
      when "10" =>
        output(3)<='0';
        output(2)<=input;
        output(1)<='0';
        output(0)<='0';
      when others =>
        output(3)<=input;
        output(2)<='0';
        output(1)<='0';
        output(0)<='0';
    end case;
  end process;
end behavioral;