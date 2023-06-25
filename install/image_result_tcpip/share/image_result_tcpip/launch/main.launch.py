# Copyright 2019 Zhushi Tech, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

from launch import LaunchDescription   # launch文件的描述类
from launch_ros.actions import Node    # 节点启动的描述类


def generate_launch_description():     # 自动生成launch文件的函数

   return LaunchDescription([               # 返回launch文件的描述信息
      Node(                                 # 配置一个节点的启动
         package='image_result_tcpip',             # 节点所在的功能包
         executable='image_result_tcpip_node'      # 节点的可执行文件名
      )
   ])