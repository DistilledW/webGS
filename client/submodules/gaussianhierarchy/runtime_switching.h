/*
 * Copyright (C) 2024, Inria
 * GRAPHDECO research group, https://team.inria.fr/graphdeco
 * All rights reserved.
 *
 * This software is free for non-commercial, research and evaluation use
 * under the terms of the LICENSE.md file.
 *
 * For inquiries contact  george.drettakis@inria.fr
 */

#pragma once
#include <cstdio>
#include <tuple>
#include <string>

class Switching
{
public:

	static int expandToTarget(
		int N,
		int target,
		int* nodes,
		int* render_indices
	);

	static int forceSearch(
		int N, 						// point number
		float* c_boxes, 			// children's boxes
		float* p_boxes, 			// parents' boxes
		float* means3d, 
		float threshold, 			// target size
		float* viewpoint,
		float x, float y, float z,
		bool if_culling,			// frustum culling 
		float* view_transform,
		float* projection_matrix,	
		bool* leafs_tag, 
		// Output 
		int* last_frame,			// 上一次用到该 gs point有多久。
		int* render_indices, 
		float* interpolation_weights) ;

	static void getTsIndexed(
		int N,
		int* indices,
		float target_size,
		float* child_boxes,
		float* parent_boxes,
		float vx, float vy, float vz,
		float x, float y, float z,
		float* ts,
		// int* kids,
		void* stream
	);
	static void changeToSizeStep(
		float target_size,
		int N,
		int* node_indices,
		int* new_node_indices,
		int* nodes,
		float* boxes,
		float* viewpoint,
		float x, float y, float z,
		int* split,
		int* render_indices,
		int* parent_indices,
		int* nodes_of_render_indices,
		int* nodes_to_expand,
		float* debug,
		char*& scratchspace,
		size_t& scratchspacesize,
		int* NsrcI,
		int* NdstI,
		char* NdstC,
		int* numI,
		int maxN,
		int& add_success,
		int* new_N,
		int* new_R,
		int* need_expansion,
		void* maintenanceStream);

	static void markVisibleForAllViewpoints(
		float target_size,
		int* nodes,
		int num_nodes,
		float* boxes,
		float* viewpoints,
		int num_viewpoints,
		int* seen,
		float zx,
		float zy,
		float zz
	);
};