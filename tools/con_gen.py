import xml.etree.ElementTree as ET
import sys
import textwrap
import time

xml_files = []
arg_num = len(sys.argv)
for arg in sys.argv:
	if arg != sys.argv[0]:
		xml_files.append(arg)

print("XML FILES: ", xml_files)



indent = '    '

# Open new file
cpp_file = open('../src/conversions.cpp', 'w')

cpp_file.write('// This file was created using AirServer tool "con_gen.py"\n')
cpp_file.write('// Generated cpp code for converting mavlink to json\n')
cpp_file.write('// This code was generated on '+time.strftime("%d/%m/%Y")+' at '+time.strftime("%I:%M:%S")+'\n\n')

# Create base template
cpp_file.write('#include "../include/conversions.h"\n')
cpp_file.write('#include <string>\n')
cpp_file.write('#include <sstream>\n\n')

cpp_file.write('#include "../include/messages.h"\n\n')
cpp_file.write('#include "../include/jsmn.h"\n\n')


## Mavlink to JSON conversion
cpp_file.write('int mav_to_json(Message &message) {\n\n')
cpp_file.write(indent+'int msgid = message.mavlink.msgid;\n')
cpp_file.write(indent+'int sysid = message.mavlink.sysid;\n')
cpp_file.write(indent+'message.json.clear();\n\n')

cpp_file.write(indent+'std::ostringstream stream;\n\n')

cpp_file.write(indent+'switch (msgid) {\n')

for file in xml_files:
	tree = ET.parse(file)
	root = tree.getroot()

	for msg in root.iter('message'):
		msg_id = msg.get('id')
		msg_name = msg.get('name')
		msg_name_l = msg_name.lower() # lower case name
		#try:
			#desc = msg.find('description').text
		#except:
			#desc = ''
		desc = ''

		cpp_file.write(indent+indent+'case MAVLINK_MSG_ID_'+msg_name+': \n')
		cpp_file.write(indent+indent+indent+'// msgid = '+msg_id+'\n')
		#cpp_file.write(indent+indent+indent+'// '+desc+'\n')
		cpp_file.write(indent+indent+indent+'mavlink_'+msg_name_l+'_t '+msg_name_l+';\n')
		cpp_file.write(indent+indent+indent+'mavlink_msg_'+msg_name_l+'_decode(&message.mavlink, &('+msg_name_l+'));\n')
                cpp_file.write(indent+indent+indent+'stream << "{\\"airserver_time\\":" << message.timestamp\n')
                cpp_file.write(indent+indent+indent+indent+'<< "\\",\\"type\\":\\"'+msg_name+'"\n')
                #cpp_file.write(indent+indent+indent+'stream << "{\\"type\\":\\"'+msg_name+'"\n')
		cpp_file.write(indent+indent+indent+indent+'<< "\\",\\"system_id\\":\\"" << sysid\n')

		for field in msg:
			#print(field.attrib)
			try:
				cpp_file.write(indent+indent+indent+indent+'<< "\\",\\"'+field.get('name')+'\\":\\""') # JSON tag
				if field.get('type') == 'int8_t':
					cpp_file.write(' << static_cast<int16_t>('+msg_name_l+'.'+field.get('name')+')\n')
				elif field.get('type') == 'uint8_t':
					cpp_file.write(' << unsigned('+msg_name_l+'.'+field.get('name')+')\n')
				elif field.get('type') == 'uint8_t_mavlink_version': # Cant print this type
					pass
				else:
					cpp_file.write(' << '+msg_name_l+'.'+field.get('name')+'\n')
			except:
				pass
		cpp_file.write(indent+indent+indent+indent+'<< "\\"}";\n')
		cpp_file.write('\n')
		cpp_file.write(indent+indent+indent+'message.json = stream.str();\n')
		cpp_file.write(indent+indent+indent+'return 0;\n')
		cpp_file.write('\n')

# Default case of switch statement
cpp_file.write(indent+indent+'default:\n')
cpp_file.write(indent+indent+indent+'// msgid = None\n')
cpp_file.write(indent+indent+indent+'//\n')
cpp_file.write(indent+indent+indent+'stream << "{\\"type\\":\\"CONVERSION_ERROR\\"}";\n')
cpp_file.write('\n')
cpp_file.write(indent+indent+indent+'message.json = stream.str();\n')
cpp_file.write(indent+indent+indent+'return 0;\n')
cpp_file.write('\n')

cpp_file.write(indent+'}\n')
cpp_file.write(indent+'return -1;\n')
cpp_file.write('}\n')


## JSON to MAVLINK

cpp_file.write('int json_to_mav(Message &message) {\n\n')

cpp_file.write(indent+'int i,r;\n')
cpp_file.write(indent+'jsmn_parser p;\n')
cpp_file.write(indent+'jsmntok_t t[128]; /* We expect no more than 128 tokens */\n\n')

cpp_file.write(indent+'jsmn_init(&p);\n\n')
cpp_file.write(indent+'r = jsmn_parse(&p, message.json.c_str(), strlen(message.json.c_str()), t, sizeof(t)/sizeof(t[0]));\n')
cpp_file.write(indent+'if (r < 0) {\n')
cpp_file.write(indent+indent+'printf("Failed to parse JSON: %d\\n", r);\n')
cpp_file.write(indent+indent+'return 1;\n')
cpp_file.write(indent+'}\n\n')

cpp_file.write(indent+'/* Assume the top-level element is an object */\n')
cpp_file.write(indent+'if (r < 1 || t[0].type != JSMN_OBJECT) {\n')
cpp_file.write(indent+indent+'printf("Object expected\\n");\n')
cpp_file.write(indent+indent+'return 1;\n')
cpp_file.write(indent+'}\n\n')

cpp_file.write(indent+'if(jsoneq(message.json.c_str(), &t[0], "type")) i = 0;\n')
cpp_file.write(indent+'if(jsoneq(message.json.c_str(), &t[0], "type")) i = 1;\n')
cpp_file.write(indent+'else return -1;\n')


cpp_file.write(indent+'for\n')

cpp_file.write(indent+'return -1;\n')
cpp_file.write('}\n')
